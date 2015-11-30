GameObject* Factoria::createGameObject(ID play)
{
	switch (id)
	{
	case "play":
		return new play();
		break;
	case "exit":
		return new exit();
		break;
	}
}