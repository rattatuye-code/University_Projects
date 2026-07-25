window.addEventListener("DOMContentLoaded", () => {
    const ws = new WebSocket("ws://localhost:8080/");
    const boardDiv = document.getElementById("board");
    const userCountSpan = document.getElementById("userCount");
    const resetBtn = document.getElementById("resetBtn");
    
    let selectedPiece = null;
    let currentBoard = [];

    // เมื่อได้รับข้อความจากเซิร์ฟเวอร์
    ws.onmessage = (event) => {
        const data = JSON.parse(event.data);
        if (data.type === "board") {
            currentBoard = data.board;
            userCountSpan.textContent = data.users;
            renderBoard(currentBoard);
        }
    };

    // ปุ่ม Reset เริ่มเกมใหม่
    resetBtn.addEventListener("click", () => {
        ws.send(JSON.stringify({ action: "reset" }));
    });

    // ฟังก์ชันวาดกระดาน
    function renderBoard(boardState) {
        boardDiv.innerHTML = "";
        for (let r = 0; r < 8; r++) {
            for (let c = 0; c < 8; c++) {
                const cell = document.createElement("div");
                // สลับสีช่องแบบตารางหมากรุก
                cell.className = cell ${(r + c) % 2 === 1 ? 'dark' : 'light'};
                
                const pieceVal = boardState[r][c];
                if (pieceVal !== 0) {
                    const piece = document.createElement("div");
                    piece.className = piece ${pieceVal === 1 ? 'p1' : 'p2'};
                    cell.appendChild(piece);
                }

                // เมื่อคลิกที่ช่องใดๆ บนกระดาน
                cell.addEventListener("click", function() {
                    handleInteraction(r, c, pieceVal, this);
                });
                
                boardDiv.appendChild(cell);
            }
        }
    }

    // ฟังก์ชันจัดการการคลิก
    function handleInteraction(r, c, pieceVal, cellElement) {
        if (selectedPiece) {
            // ถ้ายกเลิกการเลือกตัวเอง
            if (selectedPiece.r === r && selectedPiece.c === c) {
                selectedPiece = null;
                renderBoard(currentBoard); // รีเฟรชเพื่อลบขอบสีเหลือง
                return;
            }
            
            // ส่งคำสั่งย้ายหมากไปยังเซิร์ฟเวอร์
            ws.send(JSON.stringify({
                action: "move",
                from: { r: selectedPiece.r, c: selectedPiece.c },
                to: { r: r, c: c }
            }));
            selectedPiece = null;
        } else {
            // ถ้ายังไม่ได้เลือกหมาก และช่องนั้นมีหมากอยู่
            if (pieceVal !== 0) {
                selectedPiece = { r, c };
                cellElement.firstChild.classList.add("selected");
            }
        }
    }
});
