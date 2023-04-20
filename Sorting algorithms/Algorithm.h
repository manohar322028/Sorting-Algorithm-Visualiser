#pragma once
#include"button.h"
#include"node.h"
//Constant for Node Change Speed
#define SPEED (200)
bool check = false;
void _msort(int array[], int const begin, int const end, Node* nodes[], int n, sf::RenderWindow& window);
void _merge(int array[], int const left, int const mid, int const right, Node* nodes[], int nodeCount, sf::RenderWindow& window);

//Function to draw and display the all the Nodes
void renderNodes(Node* nodes[], int nodeCount, sf::RenderWindow& window,std::string title)
{
	//Sorting Window Background Color
	window.clear(sf::Color::Black);
	for (int i = 0; i < nodeCount; i++)
	{
		sf::RectangleShape* rectangle = nodes[i]->getShape();
		window.draw(*rectangle); 
	}
	sf::Font font;
	font.loadFromFile("Arial.ttf");
	sf::Text message;
	message.setFont(font);
	message.setString(title);
	message.setFillColor(sf::Color(128,0,128));
	message.setCharacterSize(20);
	message.setPosition(sf::Vector2f(20, 10));

	window.draw(message);
	window.display();
}


//Generates random numbers between 1-99
void GenerateNumbers(int* a, int nodeCount)
{
	srand(time(NULL));
	for (int i = 0; i < nodeCount; i++)
	{
		int temp = rand() % 100;
		a[i] =  temp;
	}
}


//Swaps the numbers indexed in the array
void swapNumbers(int* a, int i, int j)
{
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}


//Sorts the array using Bubble Sort Method

void BubbleSort(int* a, Node* nodes[], int nodeCount, sf::RenderWindow& window)
{

	// Color(0,102,204)		::Bluish == Sorted Node
	// Color(255,255,153)	::Yellowish == Current Node
	// Color(255,153,51)	::Orangish == Unsorted Node

	bool swapped;
	//Displays the array in initial form
	renderNodes(nodes, nodeCount, window,"Bubble Sort");
	//Sleep(SPEED);

	//Sorting Loop
	for (int i = 0; i < nodeCount; i++)
	{
		swapped = true;
		for (int j = 0; j < nodeCount - i - 1; j++)
		{
			//Shows nodes being compared
			nodes[j]->changeNodeColor(sf::Color(255, 255, 153));
			nodes[j + 1]->changeNodeColor(sf::Color(255, 255, 153));
			renderNodes(nodes, nodeCount, window, "Bubble Sort");
			Sleep(SPEED);

			//Comparing the two nodes
			if (a[j] > a[j + 1])
			{
				swapped = false;
				swapNumbers(a, j, j + 1);
				nodes[j]->setNode(a[j]);
				nodes[j + 1]->setNode(a[j + 1]);
			}

			renderNodes(nodes, nodeCount, window, "Bubble Sort");
			Sleep(SPEED);
			nodes[j]->changeNodeColor(sf::Color(255, 153, 51));
			nodes[j + 1]->changeNodeColor(sf::Color(255, 153, 51));
		}
		nodes[nodeCount - 1 - i]->changeNodeColor(sf::Color(255, 153, 51));

		//Changing the sorted nodes color
		if (swapped == true)
		{
			for (int i = 0; i < nodeCount; i++)
				nodes[i]->changeNodeColor(sf::Color(0, 102, 204));
			renderNodes(nodes, nodeCount, window, "Bubble Sort");
			Sleep(SPEED);
			break;
		}
		nodes[nodeCount - i - 1]->changeNodeColor(sf::Color(0, 102, 204));
		renderNodes(nodes, nodeCount, window, "Bubble Sort");
	}

	for (int k = 0; k < nodeCount; k++)
		nodes[k]->changeNodeColor(sf::Color(0, 102, 204));
	renderNodes(nodes, nodeCount, window, "Bubble Sort");
	Sleep(2000);
}


//Sorts the array using Insertion Sort Method

void InsertionSort(int* numbers, Node* nodes[], int nodeCount, sf::RenderWindow& window)
{
	// Color(0,102,204)		::Bluish == Sorted Node
	// Color(255,255,153)	::Yellowish == Current Node
	// Color(255,153,51)	::Orangish == Unsorted Node

	//Displaying Initial Array
	renderNodes(nodes, nodeCount, window, "Insertion Sort");
	Sleep(SPEED);

	//Sorting Loop
	for (int i = 0; i < nodeCount; i++)
	{
		//Showing the selected node
		nodes[i]->changeNodeColor(sf::Color(255, 255, 153));
		renderNodes(nodes, nodeCount, window, "Insertion Sort");
		Sleep(SPEED);

		for (int j = i; j > 0; j--)
		{
			if (numbers[j - 1] > numbers[j])
			{
				swapNumbers(numbers, j - 1, j);
				nodes[j]->setNode(numbers[j]);
				nodes[j - 1]->setNode(numbers[j - 1]);
				nodes[j - 1]->changeNodeColor(sf::Color(255, 255, 153));
				//nodes[j]->changeNodeColor(sf::Color(0, 102, 204));
				nodes[j]->changeNodeColor(sf::Color::Blue);
				renderNodes(nodes, nodeCount, window, "Insertion Sort");
				Sleep(SPEED);
			}
		}
		//Changing sorted node color
		for (int k = 0; k <= i; k++)
			nodes[k]->changeNodeColor(sf::Color::Blue);
			//nodes[k]->changeNodeColor(sf::Color(0, 102, 204));
		renderNodes(nodes, nodeCount, window, "Insertion Sort");
		Sleep(SPEED);
	}
	//Changing the sorted node color
	for (int k = 0; k < nodeCount; k++)
		nodes[k]->changeNodeColor(sf::Color::Blue);
		//nodes[k]->changeNodeColor(sf::Color(0, 102, 204));
	renderNodes(nodes, nodeCount, window, "Insertion Sort");


	/*//Displaying the message after the sorting is completed
	sf::Font font;
	font.loadFromFile("Heaters.otf");
	sf::Text message;
	message.setFont(font);
	message.setString("The array is Sorted using Insertion Sort.");
	message.setFillColor(sf::Color::Red);
	message.setCharacterSize(100);
	message.setPosition(sf::Vector2f(50, window.getSize().y * (0.1/ 4.f)));

	window.draw(message);*/
	window.display();
	Sleep(3000);
}


//Sorts the array using Selection Sort method

void SelectionSort(int* a, Node* nodes[], int nodeCount, sf::RenderWindow& window)
{
	// Color(0,102,204)		::Bluish == Sorted Node
	// Color(255,255,153)	::Yellowish == Current Node
	// Color(255,153,51)	::Orangish == Unsorted Node
	//Color(178,255,102) == Current Minimum



	//Displaying Initial Array
	renderNodes(nodes, nodeCount, window, "Selection Sort");

	Sleep(SPEED);


	//Sorting Loop
	for (int i = 0; i < nodeCount; i++)
	{
		int minIndex = i;
		int min = a[i];
		for (int j = i; j < nodeCount; j++)
		{
			//Changing Selected Node color
			nodes[j]->changeNodeColor(sf::Color(255, 255, 153));
			renderNodes(nodes, nodeCount, window, "Selection Sort");
			Sleep(SPEED);

			//Selecting the minimum node
			if (j == i)
			{
				nodes[j]->changeNodeColor(sf::Color(178, 255, 102));
				renderNodes(nodes, nodeCount, window, "Selection Sort");
				Sleep(SPEED);
			}
			else if (a[j] <= min)
			{
				nodes[minIndex]->changeNodeColor(sf::Color(255, 153, 51));
				renderNodes(nodes, nodeCount, window, "Selection Sort");
				Sleep(SPEED);
				minIndex = j;
				min = a[j];
				nodes[minIndex]->changeNodeColor(sf::Color(178, 255, 102));
				renderNodes(nodes, nodeCount, window, "Selection Sort");
				Sleep(SPEED);
			}
			else
			{
				nodes[j]->changeNodeColor(sf::Color(255, 153, 51));
				renderNodes(nodes, nodeCount, window, "Selection Sort");
			}
		}

		//Sorting the minimum node
		swapNumbers(a, i, minIndex);
		nodes[i]->setNode(a[i]);
		nodes[minIndex]->setNode(a[minIndex]);
		nodes[minIndex]->changeNodeColor(sf::Color(255, 153, 51));

		//Changing sorted node color
		nodes[i]->changeNodeColor(sf::Color(0, 102, 204));
		renderNodes(nodes, nodeCount, window, "Selection Sort");

	}

	//Changing sorted node color
	nodes[nodeCount - 1]->changeNodeColor(sf::Color(0, 102, 204));
	renderNodes(nodes, nodeCount, window, "Selection Sort");
	window.display();
	Sleep(3000);
}

void MergeSort(int* a, Node* nodes[], int nodeCount, sf::RenderWindow& window)
{
	// Color(0,102,204)		::Bluish == Sorted Node
	// Color(255,255,153)	::Yellowish == Current Node
	// Color(255,153,51)	::Orangish == Unsorted Node
	//Color(178,255,102) == Current Minimum



	//Displaying Initial Array
	renderNodes(nodes, nodeCount, window, "Merge Sort");

	Sleep(SPEED);
	_msort(a, 0, nodeCount - 1,nodes, nodeCount,window);


	
	
	renderNodes(nodes, nodeCount, window, "Merge Sort");
	window.display();
	Sleep(3000);
}

void _msort(int array[], int const begin, int const end, Node* nodes[], int n, sf::RenderWindow& window)
{
	if (begin >= end)
		return; // Returns recursivly

	auto mid = begin + (end - begin) / 2;
	/*for (auto i = begin; i <= mid; i++)
	{
		nodes[i]->changeNodeColor(sf::Color(0, 255, 153));
		renderNodes(nodes, n, window, "Merge Sort");
		Sleep(SPEED);

	}
	for (auto j = mid + 1; j <= end; j++)
	{
		nodes[j]->changeNodeColor(sf::Color(255, 0, 153));
		renderNodes(nodes, n, window, "Merge Sort");
		Sleep(SPEED);
	}*/
	

	_msort(array, begin, mid, nodes,n,window);
	_msort(array, mid + 1, end, nodes,n,window);
	_merge(array, begin, mid, end,nodes,n, window);
}

void _merge(int array[], int const left, int const mid, int const right, Node* nodes[], int nodeCount, sf::RenderWindow& window)
{
	auto const subArrayOne = mid - left + 1;
	auto const subArrayTwo = right - mid;

	// Create temp arrays
	auto* leftArray = new int[subArrayOne],
		* rightArray = new int[subArrayTwo];

	// Copy data to temp arrays leftArray[] and rightArray[]
	for (auto i = 0; i < subArrayOne; i++)
	{
		

		leftArray[i] = array[left + i];
		
	}
	for (auto j = 0; j < subArrayTwo; j++)
	{

		
		rightArray[j] = array[mid + 1 + j];
		
	}

	renderNodes(nodes, nodeCount, window, "Merge Sort");
	Sleep(SPEED);


	auto indexOfSubArrayOne = 0, // Initial index of first sub-array
		indexOfSubArrayTwo = 0; // Initial index of second sub-array
	int indexOfMergedArray = left; // Initial index of merged array

	// Merge the temp arrays back into array[left..right]
	while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
		if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
			array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
			nodes[indexOfMergedArray]->setNode(array[indexOfMergedArray]);
			nodes[indexOfMergedArray]->changeNodeColor(sf::Color(255, 255, 153));
			
			renderNodes(nodes, nodeCount, window, "Merge Sort");
			Sleep(SPEED);
			indexOfSubArrayOne++;

		}
		else {
			array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
			nodes[indexOfMergedArray]->setNode(array[indexOfMergedArray]);
			nodes[indexOfMergedArray]->changeNodeColor(sf::Color(255, 255, 153));
			renderNodes(nodes, nodeCount, window, "Merge Sort");
			Sleep(SPEED);
			indexOfSubArrayTwo++;
		}
		indexOfMergedArray++;
	}
	// Copy the remaining elements of
	// left[], if there are any
	while (indexOfSubArrayOne < subArrayOne) {
		array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
		nodes[indexOfMergedArray]->setNode(array[indexOfMergedArray]);
			nodes[indexOfMergedArray]->changeNodeColor(sf::Color(255, 255, 153));
		renderNodes(nodes, nodeCount, window, "Merge Sort");
		Sleep(SPEED);
		indexOfSubArrayOne++;
		indexOfMergedArray++;
	}
	// Copy the remaining elements of
	// right[], if there are any
	while (indexOfSubArrayTwo < subArrayTwo) {
		array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
		nodes[indexOfMergedArray]->setNode(array[indexOfMergedArray]);
		nodes[indexOfMergedArray]->changeNodeColor(sf::Color(255, 255, 153));
		renderNodes(nodes, nodeCount, window, "Merge Sort");
		Sleep(SPEED);
		indexOfSubArrayTwo++;
		indexOfMergedArray++;
	}

	

		for (auto i= left; i<indexOfMergedArray; i++)
		nodes[i]->changeNodeColor(sf::Color(0, 102, 204));
		
		renderNodes(nodes, nodeCount, window, "Merge Sort");
		Sleep(SPEED);
	
}


//Function to render the sorting window

void sortingWindow(std::string title, int a)
{

	//Required variables
	const int nodeCount = 20;
	Node* nodes[nodeCount];
	int numbers[nodeCount];

	//Generating an array of random numbers
	GenerateNumbers(numbers, nodeCount);


	//Rendering the window to display sorting animation
	sf::RenderWindow window(sf::VideoMode(1200, 600), title, sf::Style::Default);//1620, 920
	//window.setFramerateLimit(1000);

	//node width and height per single value
	float node_width = ((window.getSize().x) / (nodeCount));
	float node_height = ((window.getSize().y-250.f) / 100.f);


	//Creating all the nodes as bars
	nodes[0] = new Node(0.0f, 600, node_width, node_height, (float)numbers[0]);
	
	for (int i = 1; i < nodeCount; i++)
	{
		sf::Vector2f pos = nodes[i - 1]->getNodePosition();
		nodes[i] = new Node(pos.x + node_width, 600, node_width, node_height, (float)numbers[i]);
	}


	// loop till the window is open
	while (window.isOpen())
	{
		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			//Deciding whish sorting algorithm to apply and closing the window after the sorting is completed
			if (a == 1)
			{
				check = false;
				BubbleSort(numbers, nodes, nodeCount, window);
				window.close();	
			}
			else if (a == 2)
			{
				check = false;
				InsertionSort(numbers, nodes, nodeCount, window);
				window.close();
			}
			else if (a == 3)
			{
				check = true;
				SelectionSort(numbers, nodes, nodeCount, window);
				window.close();
			}
			else if (a == 4)
			{
				check = true;
				MergeSort(numbers, nodes, nodeCount, window);
				window.close();
			}
		}
	}

	//Deleting all the nodes created
	for (int i = 0; i < nodeCount; i++)
	{
		delete nodes[i];
	}
}
