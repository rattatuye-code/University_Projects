local prompt = script.Parent:WaitForChild("ProximityPrompt")
local tool_meat = game.ServerStorage:WaitForChild("meat")

prompt.Triggered:Connect(function (Player)
	if Player.Character and not Player.Backpack :FindFirstChild("tool_meat.name")
		and not Player.Character:FindFirstChild(tool_meat.Name) then
		
		local tool1 = tool_meat:Clone()
		
		Player.Character.Humanoid:EquipTool(tool1)
	end
end)
