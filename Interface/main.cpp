

#include <SFML/Graphics.hpp>

using namespace sf;//�������� ������������ ���� sf, ����� ��������� �� ������ sf::
int main()
{
	RenderWindow window(sf::VideoMode(640, 480), "Helicopter"); //��������� ��� �������� ������ ����

	Image heroimage; //������� ������ Image (�����������)
	heroimage.loadFromFile("images/������.png");//��������� � ���� ����

	Texture herotexture;//������� ������ Texture (��������)
	herotexture.loadFromImage(heroimage);//�������� � ���� ������ Image (�����������)

	Sprite herosprite;//������� ������ Sprite(������)
	herosprite.setTexture(herotexture);//������� � ���� ������ Texture (��������)
	herosprite.setPosition(50, 25);//������ ��������� ���������� ��������� �������

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(herosprite);//������� ������ �� �����
		window.display();
	}

	return 0;
}
