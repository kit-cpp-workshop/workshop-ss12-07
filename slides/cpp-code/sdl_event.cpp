while(1){
	SDL_Event event;
	/* Loop until there are no events left on the queue */
	while(SDL_PollEvent(&event)) {
		switch(event.type) { /* Process the appropriate event type */
			case SDL_KEYDOWN:  /* Handle a KEYDOWN event */
				printf("Oh! Key press\n");
				break;
			case SDL_MOUSEMOTION:
				.
				.
				.
			default: /* Report an unhandled event */
				printf("I don't know what this event is!\n");
		}
	}
	// do some other stuff here -- draw your app, 
	// play your music, perform other operations...
}
