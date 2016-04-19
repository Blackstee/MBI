#include <SFML/Graphics.hpp>
#include <windows.h>
#include <string.h>
#include "Tcp-client.h"

using namespace sf;

int main(){
    SOCKET s1 = start_work();
    RenderWindow win(VideoMode(1366, 768), "Krevetochka", Style::Fullscreen);
    int y = 444;
    Image i_left, i_right, i_go, i_w, i_s;
    i_left.loadFromFile("Left.png");
    i_left.createMaskFromColor(Color::White);
    i_right.loadFromFile("Right.png");
    i_right.createMaskFromColor(Color::White);
    i_go.loadFromFile("forward.png");
    i_go.createMaskFromColor(Color::White);
    i_w.loadFromFile("up_on.png");
    i_w.createMaskFromColor(Color::White);
    i_s.loadFromFile("gown_on");
    i_s.createMaskFromColor(Color::White);


    Texture t_fon, t_left, t_right, t_go, t_null;
    Texture t_w;
	t_fon.loadFromFile("font.png");
	t_left.loadFromImage(i_left);
	t_right.loadFromImage(i_right);
    t_go.loadFromImage(i_go);
    t_w.loadFromImage(i_w);



    Sprite s_fon, s_left, s_right, s_go, s_cur, s_w;
    Sprite * s_curr = NULL;
    s_fon.setTexture(t_fon);
    s_left.setTexture(t_left);
    s_left.setTextureRect(IntRect(0, 0, 348, 43));
    s_left.setPosition(0, y);
    s_right.setTexture(t_right);
    s_right.setTextureRect(IntRect(0, 0, 348, 45));
    s_right.setPosition(1017, y);
    s_go.setTexture(t_go);
    s_go.setTextureRect(IntRect(0, 0, 127, 179));
    s_go.setPosition(620, 0);
    s_w.setTexture(t_w);
    s_w.setTextureRect(IntRect(0, 10, 127, 110));
    s_w.setPosition(610, 550);

    int lll = 0;
    while (win.isOpen() && s1 != NULL){
        s_cur = s_fon;
        Event event;
        while (win.pollEvent(event)){
            if (event.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape)){
                win.close();
                end_work(s1);
            }
        }
        //char * str_to_send = (char*)malloc(sizeof(char)*20);
        //str_to_send = send_mess(s1);
        if(Keyboard::isKeyPressed(Keyboard::Left)){
            send_mess(s1, "s");
            s_cur = s_left;
            lll = 1;
        }
        if(Keyboard::isKeyPressed(Keyboard::Up)){
            send_mess(s1, "as");
            s_cur = s_go;
            lll = 1;
        }
        if(Keyboard::isKeyPressed(Keyboard::Right)){
            send_mess(s1, "a");
            s_cur = s_right;
            lll = 1;
        }
        if(Keyboard::isKeyPressed(Keyboard::W)){
            send_mess(s1, "as");
            s_cur = s_w;
            lll = 1;
        }
        if(Keyboard::isKeyPressed(Keyboard::S)){
            send_mess(s1, "zx");
            //s_cur = s_w;
            lll = 1;
        }
        if(Keyboard::isKeyPressed(Keyboard::Z)){
            send_mess(s1, "z");
            //s_cur = s_w;
            lll = 1;
        }
        if(Keyboard::isKeyPressed(Keyboard::X)){
            send_mess(s1, "x");
            //s_cur = s_w;
            lll = 1;
        }
        win.clear();
        win.draw(s_fon);
        if(lll == 1)
            win.draw(s_cur);
        win.display();
        lll = 0;
        //memset(str_to_send, 0, 20);
    }
    return 0;
}
