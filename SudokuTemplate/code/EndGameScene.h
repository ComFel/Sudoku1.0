/*
 * ENDGAME SCENE
 * Copyright © 2021+ Felipe Vallejo Molina
 *
 * Distributed under the Boost Software License, version  1.0
 * See documents/LICENSE.TXT or www.boost.org/LICENSE_1_0.txt
 *
 * felipevm07@gmail.com
 */


#include <memory>
#include <basics/Canvas>
#include <basics/Scene>
#include <basics/Texture_2D>
#include <basics/Timer>

namespace example
{
    using basics::Timer;
    using basics::Canvas;
    using basics::Texture_2D;
    using basics::Graphics_Context;

    class EndGameScene : public basics::Scene
    {

        typedef std::shared_ptr< basics::Texture_2D > Texture_Handle;

    public:

        enum State
        {
            UNINITIALIZED,
            LOADING,
            FADING_IN,
            WAITING,
            FADING_OUT,
            FINISHED,
            ERROR
        };

        State          state;
        bool           suspended{};

        unsigned       canvas_width;
        unsigned       canvas_height;

        float opacity;
        Timer timer;

        Texture_Handle Logo_Texture;

    public:

        EndGameScene()
        {
            state         = UNINITIALIZED;
            suspended     = true;
            canvas_width  = 1280;
            canvas_height = 720;
        };

        basics::Size2u get_view_size () override
        {
            return { canvas_width, canvas_height };
        }

        bool initialize () override;
        void suspend    () override {suspended = true;};
        void resume     () override {suspended = false;};

        void update     (float time) override;
        void render     (basics::Graphics_Context::Accessor & context) override;

    private:

        void update_loading    ();
        void update_fading_in  ();
        void update_waiting    ();
        void update_fading_out ();

    };

}