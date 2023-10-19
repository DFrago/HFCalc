#include <stdio.h>
#include <math.h>
double conv=.3048;
int distance,gs, antsel;
double lowfre, whipl,whiplm,hwd,hwdm,he1,he1m, deez,deezus;
double qwd,qwdm,he2,he2m;
char v_whip, hw_dipole, inverted_v, l_wire, inverted_l, sloping_v;
char sloping_wire, nvis ;
/*1 foot = 0.3048m */

int skyAntennaSelection(){
			printf("\n\nCHOOSE YOUR ANTENNA(input corresponding number): ");
			scanf("%d",& antsel);
			if(distance<=500){
				if(antsel==1||antsel==2||antsel==3||antsel==4){
					printf("\nShokay");
					getLowestFrequency(antsel);
				}
				else{
					printf("\nUnknown Command");
					fflush(stdin);
					skyAntennaSelection();
				}
			}
			if(distance<=1200 && distance > 500){
				/*2-7*/
				if(antsel==1||antsel==3||antsel==4||antsel==5||antsel==6||antsel==7){
					printf("\nShokay");
					getLowestFrequency(antsel);
				}
				else{
					printf("\nUnknown Command");
					fflush(stdin);
					skyAntennaSelection();
				}
			}
			if(distance>1200 && distance < 24901){
				/*5-7*/
				if(antsel==5||antsel==6||antsel==7){
					printf("\nShokay");
					getLowestFrequency(antsel);
				}
				else{
					printf("\nUnknown Command");
					fflush(stdin);
					skyAntennaSelection();
				}
			}
		}
int getLowestFrequency(antsel){
		printf("\n\nWhat is your lowest frequency?(MHz) ");
		scanf("%lf",&lowfre);
		printf("\n\n******************************************************************\n");
		if(lowfre >= 3 && lowfre <= 30){
			displayDistance(antsel);
		}
		else{
			printf("\nValue is either out of range (further than the distance around the globe)\n");
			printf("or you submitted an unknown command\n");
			fflush(stdin);
			getLowestFrequency(antsel);
		}
	}
int welcome(){
		printf("\n\nDo you want to use ground waves(1) or sky waves(2)? ");
		scanf(" %d",& gs);
		if(gs==1){
			groundWaves();
		}
		else if(gs==2){
			skyWaves();
		}
		else if(gs!=1||gs!=2){
			printf("\nUnknown Command");
			fflush(stdin);
			welcome();
		}
	}
int groundWaves(){
		char userInput[30];
		printf("\nBelow are Antennas that produce ground waves:");
		printf("\n\n(1)Vertical Whip");
		printf("\n(2)Inverted Vee");
		printf("\n(3)Long Wire");
		printf("\n(4)Inverted L");
		printf("\n(5)Sloping Vee");
		printf("\n(6)Sloping Wire");
		printf("\n\n*****All antennas listed produce both ground waves and sky waves");
		printf(" except for the vertical whip. The vertical whip"); 
		printf("\nonly produces ground waves*****");
		printf("\n\nCHOOSE YOUR ANTENNA(input corresponding number): ");
		scanf(" %s",& userInput);
		if(strcmp(userInput,"back")==0||strcmp(userInput,"Back")==0){
			welcome();
		}
		if(strcmp(userInput,"1")==0||strcmp(userInput,"2")==0||strcmp(userInput,"3")==0||strcmp(userInput,"4")==0||strcmp(userInput,"5")==0||strcmp(userInput,"6")==0){
			printf("\nShokay");
			printf("\n\nWhat is your lowest frequency?(MHz) ");
			scanf("%lf",&lowfre);
			if(lowfre<3||lowfre>30){
				printf("\nOut of HF Range. Frequency must be between 3-30 MHz\n");
				groundWaves();
			}
			if(strcmp(userInput,"1")==0){
				groundVerticalWhip();
			}
			if(strcmp(userInput,"2")==0){
				groundInvertedVee();
			}
			if(strcmp(userInput,"3")==0){
				groundLongWire();
			}
			if(strcmp(userInput,"4")==0){
				groundInvertedL();
			}
			if(strcmp(userInput,"5")==0){
				groundSlopingVee();
			}
			if(strcmp(userInput,"6")==0){
				groundSlopingWire();
			}
		}
		else{
			printf("\nUnknown Command\n");
			fflush(stdin);
			groundWaves();
		}
	}
	/*Vertical-Whip*/
	int groundVerticalWhip(){
		whipl= 234 / lowfre;
		whiplm=whipl*conv;
		printf("\n\nThe length of your whip should be %2.3lf feet / %2.3lf meters",whipl,whiplm);
		welcome();
	}

	
	/*Inverted-Vee*/
	int groundInvertedVee(){
		hwd= 468 / lowfre;
		hwdm=hwd*conv;
		qwd=hwd/2;
		qwdm=qwd*conv;
		printf("\n\n******************************************************************");
		printf("\n\nThe length of your Inverted-Vee should be %2.1lf ft / %2.1lf m",hwd,hwdm);
		printf("\n\nMeaning each element is %2.1lf ft / %2.1lf m",qwd,qwdm );
		printf("\n\nThe ideal heights for this puppy are either:");
		he1=246/lowfre;
		he1m=he1*conv;
		he2=492/lowfre;
		he2m=he2*conv;
		printf("\n\n%2.4lf ft / %2.4lf m",he1,he1m);
		printf("\nOR");
		printf("\n%2.4lf ft / %2.4lf m",he2,he2m);
		printf("\n\nor just get ole girl as high as you can get her");
		printf("\n\n******************************************************************");
		welcome();
	}
	
	/*Long-Wire*/
	int groundLongWire(){
		hwd= 468 / lowfre;
		hwdm=hwd*conv;
		qwd=hwd/2;
		qwdm=qwd*conv;
		deez=hwd*2;
		deezus=hwdm*2;
		printf("\n\n******************************************************************");
		printf("\n\nThe length of your Long-Wire should be %2.1lf ft / %2.1lf m at a minimum",hwd,hwdm);
		printf("\nThis length will provide more directionality: %2.1lf ft / %2.1lf m ",deez,deezus);
		printf("\n\nThe ideal height for this antenna is 15-20 ft");
		printf("\n\n******************************************************************");
		welcome();
	}
	
	/*Inverted-L*/
	int groundInvertedL(){
		hwd= 468 / lowfre;
		hwdm=hwd*conv;
		qwd=hwd/2;
		qwdm=qwd*conv;
		printf("\n\n******************************************************************");
		printf("\n\nThe length of the Horizontal element should be %2.1lf ft / %2.1lf m",hwd,hwdm);
		printf("\n\nThe length of the vertical element is %2.1lf ft / %2.1lf m",qwd,qwdm );
		printf("\n\nThe ideal heights for this puppy are either:");
		he1=246/lowfre;
		he1m=he1*conv;
		he2=492/lowfre;
		he2m=he2*conv;
		printf("\n\n%2.4lf ft / %2.4lf m",he1,he1m);
		printf("\nOR");
		printf("\n%2.4lf ft / %2.4lf m",he2,he2m);
		printf("\nHOWEVER 35-40 FEET WILL WORK AS A RULE OF THUM FOR THE L. TRU");
		printf("\n\n******************************************************************");
		welcome();
	}
	
	/*Sloping-Vee*/
	int groundSlopingVee(){
		hwd= 468 / lowfre;
		hwdm=hwd*conv;
		qwd=hwd/2;
		qwdm=qwd*conv;
		deez=hwd*2;
		deezus=hwdm*2;
		printf("\n\n******************************************************************");
		printf("\n\nThe length of your Sloping-Vee should be %2.1lf ft / %2.1lf m at a minimum",hwd,hwdm);
		printf("\n\nMeaning each element is %2.1lf ft / %2.1lf m",qwd,qwdm );
		he1=246/lowfre;
		he1m=he1*conv;
		he2=492/lowfre;
		he2m=he2*conv;
		printf("\n\nThe ideal heights for this puppy are either:");
		printf("\n\n%2.4lf ft / %2.4lf m",he1,he1m);
		printf("\nOR");
		printf("\n%2.4lf ft / %2.4lf m",he2,he2m);
		printf("\nHOWEVER 35-40 FEET WILL WORK AS A RULE OF THUM FOR THE L. TRU");
		if(distance <= 1000 && distance > 700){
		printf("\n\nThe angle between the elements should be 60 degrees.");	
		}
		if(distance <= 1500 && distance > 1000){
		printf("\n\nThe angle between the elements should be 45 degrees.");	
		}
		if(distance > 1500){
		printf("\n\nThe angle between the elements should be 30 degrees.");	
		}
		printf("\n\n******************************************************************");
		welcome();
	}
	/*Sloping-Wire*/
	int groundSlopingWire(){
		hwd= 468 / lowfre;
		hwdm=hwd*conv;
		qwd=hwd/2;
		qwdm=qwd*conv;
		deez=hwd*2;
		deezus=hwdm*2;
		printf("\n\n******************************************************************");
		printf("\n\nThe length of your Sloping-Wire should be %2.1lf ft / %2.1lf m at a minimum",hwd,hwdm);
		printf("\nThis length will provide more directionality: %2.1lf ft / %2.1lf m ",deez,deezus);
		printf("\n\nThe ideal height for this antenna is 15-20 ft");
		printf("\n\n******************************************************************");
		welcome();	
	}
	
int skyWaves(){
		printf("\nHow far are you trying to shoot?(miles)  ");
		scanf("%d",& distance);
		if(distance>24901||distance<=0){
			printf("\nValue is either out of range (further than the distance around the globe)\n");
			printf("or you submitted an unknown command\n");
			fflush(stdin);
			skyWaves();
		}
		else{
			printf("\nThe optimal antennas for this distance are: \n\n");
			if(distance<=500){
				printf("\n(1)NVIS (Omnidirectional)");
				printf("\n(2)Half-Wave Dipole (Bi-directional)");
				printf("\n(3)Inverted Vee (Bi-directional)");
				printf("\n(4)Inverted L (Bi-directional/Omnidirectional)");
			}	
		 	if(distance<=1200 && distance > 500){
				printf("\n(2)Half-Wave Dipole (Bi-directional)");
				printf("\n(3)Inverted Vee (Bi-directional)");
				printf("\n(5)Long Wire (Bi-directional/Directional)");
				printf("\n(4)Inverted L (Bi-directional/Omnidirectional)");
				printf("\n(6)Sloping Vee (Directional)");
				printf("\n(7)Sloping Wire (Bi-directional/Directional)");
				}

		 	if(distance>1200 && distance < 24901){
				printf("\n(5)Long Wire (Bi-directional/Directional)");
				printf("\n(6)Sloping Vee (Directional)");
				printf("\n(7)Sloping Wire (Bi-directional/Directional)");
			}
			skyAntennaSelection();
		}
}
		
int displayDistance(antsel){
		if(antsel != 5){

			if(distance<=50){
				printf("\nYour daytime take-off angle is 80 degrees.");
			}
			if(distance<=95 && distance > 50 ){
				printf("\nYour daytime take-off angle is 70 degrees.");
			}
			if(distance<=160 && distance > 95 ){
				printf("\nYour daytime take-off angle is 60 degrees.");
			}
			if(distance<=250 && distance > 160 ){
				printf("\nYour daytime take-off angle is 50 degrees.");
			}
			if(distance<=275 && distance > 250 ){
				printf("\nYour daytime take-off angle is 45 degrees.");
			}
			if(distance<=350 && distance > 275 ){
				printf("\nYour daytime take-off angle is 40 degrees.");
			}
			if(distance<=400 && distance > 350 ){
				printf("\nYour daytime take-off angle is 35 degrees.");
			}
			if(distance<=450 && distance > 400 ){
				printf("\nYour daytime take-off angle is 30 degrees.");
			}
			if(distance<=600 && distance > 450 ){
				printf("\nYour daytime take-off angle is 25 degrees.");
			}
			if(distance<=700 && distance > 600 ){
				printf("\nYour daytime take-off angle is 20 degrees.");
			}
			if(distance<=900 && distance > 700 ){
				printf("\nYour daytime take-off angle is 15 degrees.");
			}
			if(distance<1200 && distance > 900 ){
				printf("\nYour daytime take-off angle is 10 degrees.");
			}
			if(distance<=1500 && distance > 1200 ){
				printf("\nYour daytime take-off angle is 5 degrees.");
			}
			if(distance >= 2000 ){
				printf("\nYour daytime take-off angle is 0 degrees.");
			}
/*There are 28 IF CONDITIONALS. There has got to be a better way to do this. */

			if(distance <=90){
				printf("\nYour nighttime take-off angle is 80 degrees.");
			}
			if(distance <=180 && distance > 90){
				printf("\nYour nighttime take-off angle is 70 degrees.");
			}
			if(distance <=275 && distance > 180){
				printf("\nYour nighttime take-off angle is 60 degrees.");
			}
			if(distance <=425 && distance > 275){
				printf("\nYour nighttime take-off angle is 50 degrees.");
			}
			if(distance <=500 && distance > 425){
				printf("\nYour nighttime take-off angle is 45 degrees.");
			}
			if(distance <=600 && distance > 500){
				printf("\nYour nighttime take-off angle is 40 degrees.");
			}
			if(distance <=700 && distance > 600){
				printf("\nYour nighttime take-off angle is 35 degrees.");
			}
			if(distance <=825 && distance > 700){
				printf("\nYour nighttime take-off angle is 30 degrees.");
			}
			if(distance <=1000 && distance > 825){
				printf("\nYour nighttime take-off angle is 25 degrees.");
			}
			if(distance <=1100 && distance > 1000){
				printf("\nYour nighttime take-off angle is 20 degrees.");
			}
			if(distance <=1400 && distance > 1100){
				printf("\nYour nighttime take-off angle is 15 degrees.");
			}
			if(distance <=1800 && distance > 1400){
				printf("\nYour nighttime take-off angle is 10 degrees.");
			}
			if(distance <=2300 && distance > 1800){
				printf("\nYour nighttime take-off angle is 5 degrees.");
			}
			if(distance >=2800){
				printf("\nYour nighttime take-off angle is 0 degrees.");
			}
	}
	skywaveResults(antsel);
}
int skywaveResults(antsel){
	/*NVIS*/
	if(antsel==1){
		hwd= 468 / lowfre;
		hwdm=hwd*conv;
		qwd=hwd/2;
		qwdm=qwd*conv;
		printf("\n\n******************************************************************");
		printf("\nThis antenna is comprised of two crossed sloping dipoles");
		printf("\npositioned at right angles to each other.");
		printf("\n\nThe length of your Sloping Dipoles should be %2.1lf ft / %2.1lf m",hwd,hwdm);
		printf("\n\nMeaning each element is %2.1lf ft / %2.1lf m",qwd,qwdm );
		printf("\n\nThe ideal height for this puppy is 15ft");
		printf("\n\n******************************************************************");
	}

	/*Half-Wave Dipole*/
	if(antsel==2){
		hwd= 468 / lowfre;
		hwdm=hwd*conv;
		qwd=hwd/2;
		qwdm=qwd*conv;
		printf("\n\n******************************************************************");
		printf("\n\nThe length of your Half-Wave Dipole should be %2.1lf ft / %2.1lf m",hwd,hwdm);
		printf("\n\nMeaning each element is %2.1lf ft / %2.1lf m",qwd,qwdm );
		printf("\n\nThe ideal heights for this puppy are either:");
		he1=246/lowfre;
		he1m=he1*conv;
		he2=492/lowfre;
		he2m=he2*conv;
		printf("\n\n%2.4lf ft / %2.4lf m",he1,he1m);
		printf("\nOR");
		printf("\n%2.4lf ft / %2.4lf m",he2,he2m);
		printf("\n\nor just get ole girl as high as you can get her");
		printf("\n\n******************************************************************");
	}

	/*Inverted-Vee*/
	if(antsel==3){
		hwd= 468 / lowfre;
		hwdm=hwd*conv;
		qwd=hwd/2;
		qwdm=qwd*conv;
		printf("\n\n******************************************************************");
		printf("\n\nThe length of your Inverted-Vee should be %2.1lf ft / %2.1lf m",hwd,hwdm);
		printf("\n\nMeaning each element is %2.1lf ft / %2.1lf m",qwd,qwdm );
		printf("\n\nThe ideal heights for this puppy are either:");
		he1=246/lowfre;
		he1m=he1*conv;
		he2=492/lowfre;
		he2m=he2*conv;
		printf("\n\n%2.4lf ft / %2.4lf m",he1,he1m);
		printf("\nOR");
		printf("\n%2.4lf ft / %2.4lf m",he2,he2m);
		printf("\n\nor just get ole girl as high as you can get her");
		printf("\n\n******************************************************************");
	}

	/*Inverted-L*/
	if(antsel==4){
		hwd= 468 / lowfre;
		hwdm=hwd*conv;
		qwd=hwd/2;
		qwdm=qwd*conv;
		printf("\n\n******************************************************************");
		printf("\n\nThe length of the Horizontal element should be %2.1lf ft / %2.1lf m",hwd,hwdm);
		printf("\n\nThe length of the vertical element is %2.1lf ft / %2.1lf m",qwd,qwdm );
		printf("\n\nThe ideal heights for this puppy are either:");
		he1=246/lowfre;
		he1m=he1*conv;
		he2=492/lowfre;
		he2m=he2*conv;
		printf("\n\n%2.4lf ft / %2.4lf m",he1,he1m);
		printf("\nOR");
		printf("\n%2.4lf ft / %2.4lf m",he2,he2m);
		printf("\nHOWEVER 35-40 FEET WILL WORK AS A RULE OF THUM FOR THE L. TRU");
		printf("\n\n******************************************************************");
	}

	/*Long-Wire*/
	if(antsel==5){
		hwd= 468 / lowfre;
		hwdm=hwd*conv;
		qwd=hwd/2;
		qwdm=qwd*conv;
		deez=hwd*2;
		deezus=hwdm*2;
		printf("\n\n******************************************************************");
		printf("\n\nThe length of your Long-Wire should be %2.1lf ft / %2.1lf m at a minimum",hwd,hwdm);
		printf("\nThis length will provide more directionality: %2.1lf ft / %2.1lf m ",deez,deezus);
		printf("\n\nThe ideal height for this antenna is 15-20 ft");
		printf("\n\n******************************************************************");
	}

	/*Sloping-Vee*/
	if(antsel==6){
		hwd= 468 / lowfre;
		hwdm=hwd*conv;
		qwd=hwd/2;
		qwdm=qwd*conv;
		deez=hwd*2;
		deezus=hwdm*2;
		printf("\n\n******************************************************************");
		printf("\n\nThe length of your Sloping-Vee should be %2.1lf ft / %2.1lf m at a minimum",hwd,hwdm);
		printf("\n\nMeaning each element is %2.1lf ft / %2.1lf m",qwd,qwdm );
		he1=246/lowfre;
		he1m=he1*conv;
		he2=492/lowfre;
		he2m=he2*conv;
		printf("\n\nThe ideal heights for this puppy are either:");
		printf("\n\n%2.4lf ft / %2.4lf m",he1,he1m);
		printf("\nOR");
		printf("\n%2.4lf ft / %2.4lf m",he2,he2m);
		printf("\nHOWEVER 35-40 FEET WILL WORK AS A RULE OF THUM FOR THE Sloping-Vee. TRU");
	if(distance <= 1000 && distance > 700){
		printf("\n\nThe angle between the elements should be 60 degrees.");	
	}
	if(distance <= 1500 && distance > 1000){
		printf("\n\nThe angle between the elements should be 45 degrees.");	
	}
	if(distance > 1500){
		printf("\n\nThe angle between the elements should be 30 degrees.");	
	}
	printf("\n\n******************************************************************");
	
	}


	/*Sloping-Wire*/
	if(antsel==7){
		hwd= 468 / lowfre;
		hwdm=hwd*conv;
		qwd=hwd/2;
		qwdm=qwd*conv;
		deez=hwd*2;
		deezus=hwdm*2;
		printf("\n\n******************************************************************");
		printf("\n\nThe length of your Sloping-Wire should be %2.1lf ft / %2.1lf m at a minimum",hwd,hwdm);
		printf("\nThis length will provide more directionality: %2.1lf ft / %2.1lf m ",deez,deezus);
		printf("\n\nThe ideal height for this antenna is 15-20 ft");
		printf("\n\n******************************************************************");
	}
	welcome();
}
int main(void){
 	printf("\nWelcome to BigT's HF calculator. Created for use in conjunction with VOACAP Propogation tool.");
 	printf("\nEnter 'Back' to return to the previous page");
	welcome();
	return 0;
	
}
