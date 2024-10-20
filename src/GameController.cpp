#include "../include/GameController.h"
#include "../include/Renderer.h"
#include "../include/SpriteAnim.h"
#include "../include/SpriteSheet.h"
#include "../include/BasicStructs.h"
#include "../include/TTFont.h"
#include "../include/Timing.h"

GameController::GameController()
{
    m_sdlEvent = {};
}

GameController::~GameController()
{
}

void GameController::RunGame()
{
    std::cout << "Initializing AssetController..." << std::endl;
    AssetController::Instance().Initialize(10000000); // Allocate 10MB
    std::cout << "AssetController initialized!" << std::endl;

    std::cout << "Initializing Renderer..." << std::endl;
    Renderer* r = &Renderer::Instance();
    Timing* t = &Timing::Instance();
    r->Initialize(1920, 1080);
    std::cout << "Renderer initialized!" << std::endl;

    std::cout << "Initializing TTFont..." << std::endl;
    TTFont* font = new TTFont();
    font->Initialize(20);
    std::cout << "TTFont initialized!" << std::endl;

    // Other initialization steps
    Point ws = r->GetWindowSize();

    SpriteSheet* sheet[10];
    for (int i = 0; i < 10; i++)
    {
        SpriteSheet::Pool = new ObjectPool<SpriteSheet>();
        SpriteAnim::Pool = new ObjectPool<SpriteAnim>();
        sheet[i] = SpriteSheet::Pool->GetResource();
        sheet[i]->Load("assets/Textures/Warrior.tga");
        sheet[i]->SetSize(17, 6, 69, 44);
        sheet[i]->AddAnimation(EN_AN_IDLE, 0, 6, 0.1f);

        int randomInt = rand() % 1001;
        float randomFloat = 0.08 + (randomInt / 1000.0f) * (0.1 - 0.08);

        float normalizedSpeed = (randomFloat - 0.08f) / (0.1f - 0.08f);
        float proportionalValue = normalizedSpeed * (100.0f - 80.0f) + (80.0f);

        sheet[i]->AddAnimation(EN_AN_RUN, 6, 8, randomFloat);
        sheet[i]->AddAnimation(EN_AN_DEATH, 24, 11, 0.1f);
        sheet[i]->setSpeed(proportionalValue / 60.0);
        ofstream writeStream("resource.bin", ios::out | ios::binary);
        sheet[i]->Serialize(writeStream);
        writeStream.close();
    }

    double x[10]{ 0 };
    const int FPS = 60;
    const int frameDelay = 1000 / FPS;

    bool saved = false;
    int level = 1;

    while (m_sdlEvent.type != SDL_QUIT)
    {
        Uint32 frameStart = SDL_GetTicks(); // Capture frame start time
        t->Tick();

        if (level == 1)
        {
            if (t->getCurrentTime() / 1000 >= 5)
            {
                if (!saved)
                {
                    ofstream writeStream("Level1.bin", ios::out | ios::binary);

                    for (int i = 0; i < 10; i++)
                    {

                        sheet[i]->Serialize(writeStream);
                    }

                    writeStream.close();

                    ifstream readStream("Level1.bin", ios::in | ios::binary);

                    for (int i = 0; i < 10; i++)
                    {

                        sheet[i]->Deserialize(readStream);
                    }

                    readStream.close();

                    saved = true;
                }
            }

            SDL_PollEvent(&m_sdlEvent);
            r->SetDrawColor(Color(128, 128, 128, 0));
            r->ClearScreen();

            for (int i = 0; i < 10; i++)
            {
                x[i] += sheet[i]->getSpeed();

                r->RenderTexture(sheet[i], sheet[i]->Update(EN_AN_RUN), Rect(x[i], 10 + i * 100, 69 * 3 + x[i], 150 * i + 44 * 3));

                if (x[i] >= r->GetWindowSize().X)
                {
                    level = 2;
                }
            }

            string display = "Frames Per Second: " + to_string(t->GetFPS());
            display += "        Game Time: " + to_string(t->getCurrentTime() / 1000);
            display += "        Auto Saved: ";

            if (t->getCurrentTime() / 1000 >= 5)
                display += "Yes";

            else
                display += "No";

            font->Write(r->GetRenderer(), display.c_str(), SDL_Color{ 0, 0, 255 }, SDL_Point{ 0, 0 });

            Uint32 frameTime = SDL_GetTicks() - frameStart;
            if (frameTime < frameDelay)
            {
                SDL_Delay(frameDelay - frameTime); // Delay to cap at 60 FPS
            }

            SDL_RenderPresent(r->GetRenderer());
        }

        if (level == 2)
        {
            if (t->getCurrentTime() / 1000 >= 5)
            {
                if (!saved)
                {
                    ofstream writeStream("Level2.bin", ios::out | ios::binary);

                    for (int i = 0; i < 10; i++)
                    {
                        sheet[i]->Serialize(writeStream);
                    }

                    writeStream.close();

                    ifstream readStream("Level2.bin", ios::in | ios::binary);

                    for (int i = 0; i < 10; i++)
                    {
                        sheet[i]->Deserialize(readStream);
                    }

                    readStream.close();

                    saved = true;
                }
            }

            SDL_PollEvent(&m_sdlEvent);
            r->SetDrawColor(Color(0, 128, 0, 0));
            r->ClearScreen();

            for (int i = 0; i < 10; i++)
            {
                x[i] += sheet[i]->getSpeed();

                r->RenderTexture(sheet[i], sheet[i]->Update(EN_AN_RUN), Rect(x[i], 10 + i * 100, 69 * 3 + x[i], 150 * i + 44 * 3));

                if (x[i] >= r->GetWindowSize().X)
                {
                    level = 2;
                }
            }

            string display = "Frames Per Second: " + to_string(t->GetFPS());
            display += "        Game Time: " + to_string(t->getCurrentTime() / 1000);
            display += "        Auto Saved: ";

            if (t->getCurrentTime() / 1000 >= 5)
                display += "Yes";

            else
                display += "No";

            font->Write(r->GetRenderer(), display.c_str(), SDL_Color{ 0, 0, 255 }, SDL_Point{ 0, 0 });

            Uint32 frameTime = SDL_GetTicks() - frameStart;
            if (frameTime < frameDelay)
            {
                SDL_Delay(frameDelay - frameTime); // Delay to cap at 60 FPS
            }

            SDL_RenderPresent(r->GetRenderer());
        }
    }

    delete SpriteAnim::Pool;
    delete SpriteSheet::Pool;

    font->Shutdown();
    r->Shutdown();
}