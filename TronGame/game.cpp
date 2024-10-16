
//Game file

#define is_down(b) input->buttons[b].is_down
#define pressed(b) (input->buttons[b].is_down && input->buttons[b].changed)
#define released(b) (!input->buttons[b].is_down && input->buttons[b].changed)

struct TrailSegment {
	float y;
	float x;
};

float player1_pos_x = 0;
float player1_pos_y = 50;
int p1Dir = 4; //Dir is direction. Moves clockwise. 1 is UP, 2 is Right, 3 is down, 4 is left. 
list<TrailSegment> p1Trail; // This will store coordinites for the trail.

float player2_pos_x = 0;
float player2_pos_y = -50;
int p2Dir = 2;
list<TrailSegment> p2Trail;

//while (gamestate = menu) {Render menu and options here.}
enum Gamemode {
	GM_MENU,
	GM_GAMEPLAY,
};
Gamemode current_gamemode;
int hot_button;
bool enemy_is_ai;



//while (gamestate = gameplay) {Render game and players.}


internal void
simulate_game(Input* input, float dt) {
	//Simulate the data
	clear_screen(); //Clears the previous frame by rendering a new background over the previouse frame "clearing" the screen
	float speed = 30; //units per second





	// AI movement
	if (current_gamemode == GM_GAMEPLAY) {
		if (!enemy_is_ai) {

		

		//Player Movement
		if (is_down(BUTTON_UP) && p1Dir != 3) p1Dir = 1;
		if (is_down(BUTTON_DOWN) && p1Dir != 1) p1Dir = 3;
		if (is_down(BUTTON_LEFT) && p1Dir != 2) p1Dir = 4;
		if (is_down(BUTTON_RIGHT) && p1Dir != 4) p1Dir = 2;

		}
		else {
			//Player Movement
			if (is_down(BUTTON_UP) && p1Dir != 3) p1Dir = 1;
			if (is_down(BUTTON_DOWN) && p1Dir != 1) p1Dir = 3;
			if (is_down(BUTTON_LEFT) && p1Dir != 2) p1Dir = 4;
			if (is_down(BUTTON_RIGHT) && p1Dir != 4) p1Dir = 2;


			if (p1Dir == 1) player1_pos_x += speed * dt;
			else if (p1Dir == 3) player1_pos_x -= speed * dt;
			else if (p1Dir == 4) player1_pos_y -= speed * dt;
			else if (p1Dir == 2) player1_pos_y += speed * dt;

			if (is_down(BUTTON_W) && p2Dir != 3) p2Dir = 1;
			else if (is_down(BUTTON_S) && p2Dir != 1) p2Dir = 3;
			else if (is_down(BUTTON_A) && p2Dir != 2) p2Dir = 4;
			else if (is_down(BUTTON_D) && p2Dir != 4) p2Dir = 2;

			if (p2Dir == 1) player2_pos_x += speed * dt;
			else if (p2Dir == 3) player2_pos_x -= speed * dt;
			else if (p2Dir == 4) player2_pos_y -= speed * dt;
			else if (p2Dir == 2) player2_pos_y += speed * dt;
		}
		//Verify Current Location is not in trail data.

		//Register current localtion into trail
		TrailSegment NewSegment;
		NewSegment.x = player1_pos_x;
		NewSegment.y = player1_pos_y;
		p1Trail.push_back(NewSegment);

		NewSegment.x = player2_pos_x;
		NewSegment.y = player2_pos_y;
		p2Trail.push_back(NewSegment);

		//Draw on screen
		for (TrailSegment seg : p1Trail) {
			draw_rect(seg.y, seg.x, 1, 1, 0x009494);
		}

		for (TrailSegment seg : p2Trail) {
			draw_rect(seg.y, seg.x, 1, 1, 0xb25700);
		}

		draw_rect(player1_pos_y, player1_pos_x, 1, 1, 0x00FFFF);
		draw_rect(player2_pos_y, player2_pos_x, 1, 1, 0xFF9735);


	}
	else {

		if (pressed(BUTTON_LEFT) || pressed(BUTTON_RIGHT)) {
			hot_button = !hot_button;
		}
		if (pressed(BUTTON_ENTER)) {
			current_gamemode = GM_GAMEPLAY;
			enemy_is_ai = hot_button ? 0 : 1;
		}



		if (hot_button == 0) {
			draw_rect(20, 0, 10, 10, 0xff0000);
			draw_rect(-20, 0, 10, 10, 0xcccccc);
		}
		else {
			draw_rect(20, 0, 10, 10, 0xcccccc);
			draw_rect(-20, 0, 10, 10, 0xff0000);
		}
	}

}

//Different Windows can be done with those state machines andy was talking about.
//Order of operations is MoveP->CheckPCollision->AddLineSegment@P