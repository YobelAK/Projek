package main

import "fmt" 

type pokemon struct {
	number int
	name string
	level int
	gender string
	typee string
	tera string
	hp int
	atk int
	def int
	spd int
	spatk int
	spdef int
	ability string
	held string
	move [4]string
	location string
	date [3]int

}
type arrpoke[9999]pokemon

func main() {
	var input int
	var poke arrpoke
	var n int
	var a int
	var t bool
	
	t =true

	menu(&input)

	for input != 0 {
		a=0
		hasil := playmenu(a)
		if hasil == 1 {
			inputdatapoke(&poke, &n)
		} else if hasil == 2 {
			delete(&poke,&n)
		} else if hasil == 3 {
			changepokedata(&poke,n)
		}else if hasil == 4{
			listpokemon(poke,n)
		}else if hasil ==5 {
			searchpokemon(poke,n,&t)
		}else {
			input = 0 
		}
		fmt.Println("Pokemon total:",n)
		fmt.Println("Box total:",menentukanbox(n)+1)
		
	}

	fmt.Println("Bye - bye")
}


func menu(input *int){
	fmt.Println("Welcome to PC Box Pokemon Simulator")
	fmt.Println()
	fmt.Println()
	fmt.Println("We provide 32 boxes for you to enter Pokemon data that will be stored")
	fmt.Println()
	fmt.Println("Each box can contain 30 pokemon data so that in total you can store as many as 960 pokemon")
	fmt.Println()
	fmt.Println("Have a nice play !")
	fmt.Println("Please Select an Option Below")
	fmt.Println("1.Play")
	fmt.Println("2.Exit")
	fmt.Println()
	fmt.Println("if you want to play please input number 1, but if you dont then input number 2")
	
	fmt.Println("input your option :")
	fmt.Scanln(input)
	for *input <1 || *input >2 {
		fmt.Println("Please choose between 1 or 2")
		fmt.Println("input your option :")
		fmt.Scanln(input)
	}
}

func playmenu(input int)int{
	fmt.Println("Choose :")
	fmt.Println("1. Enter pokemon data")
	fmt.Println("2. Delete pokemon data")
	fmt.Println("3. Change pokemon data")
	fmt.Println("4. List of pokemon")
	fmt.Println("5. Search pokemon")
	fmt.Println("6. Exit")

	fmt.Println("if you want to choose option 1 then input number 1")
	fmt.Println()
	fmt.Println("Input your option :")
	fmt.Scanln(&input)
	for input <1 || input >6 {
		fmt.Println("Please put between number 1 until 6")
		fmt.Println("Input your option :")
		fmt.Scanln(&input)
	}
	return input
}

func inputdatapoke(poke *arrpoke, n *int) {
	var banyakpoke int
	var a,b int

	fmt.Println("Enter the number of pokemon to be input:")
	fmt.Println("(For example, if you want to input 2 pokemon data, enter the number 2)")
	fmt.Scanln(&banyakpoke)

	for banyakpoke < 1 {
		fmt.Println("Please enter a valid number:")
		fmt.Scanln(&banyakpoke)
	}

	b=*n+banyakpoke
	fmt.Println("You have", 32-menentukanbox(b), "box left.")

	for i := 1; i <= banyakpoke; i++ {
		fmt.Println("Pokemon", i)
		fmt.Println()
		fmt.Println("Number:")
		fmt.Scanln(&poke[*n].number)

		fmt.Println("Name:")
		fmt.Scanln(&poke[*n].name)

		fmt.Println("Level:")
		fmt.Scanln(&poke[*n].level)

		fmt.Println("Gender (M/F):")
		fmt.Scanln(&poke[*n].gender)

		for poke[*n].gender != "M" && poke[*n].gender != "F" {
			fmt.Println("Please enter a valid gender (M/F):")
			fmt.Scanln(&poke[*n].gender)
		}
		fmt.Println("Type:")
		fmt.Scanln(&poke[*n].typee)

		fmt.Println("Tera type:")
		fmt.Scanln(&poke[*n].tera)

		fmt.Println("HP:")
		fmt.Scanln(&poke[*n].hp)

		fmt.Println("Attack:")
		fmt.Scanln(&poke[*n].atk)

		fmt.Println("Defense:")
		fmt.Scanln(&poke[*n].def)

		fmt.Println("Speed:")
		fmt.Scanln(&poke[*n].spd)

		fmt.Println("Sp.Atk:")
		fmt.Scanln(&poke[*n].spatk)

		fmt.Println("Sp.Def:")
		fmt.Scanln(&poke[*n].spdef)
		
		fmt.Println("Ability")
		fmt.Scanln(&poke[*n].ability)
		
		fmt.Println("Held Item")
		fmt.Scanln(&poke[*n].held)
		
		fmt.Println("Move")
		fmt.Println("If there is none then put (-)")
		fmt.Println("Move 1")
		fmt.Scanln(&poke[*n].move[0])
		fmt.Println("Move 2")
		fmt.Scanln(&poke[*n].move[1])
		fmt.Println("Move 3")
		fmt.Scanln(&poke[*n].move[2])
		fmt.Println("Move 4")
		fmt.Scanln(&poke[*n].move[3])
		
		fmt.Println("Location")
		fmt.Scanln(&poke[*n].location)
		
		fmt.Println("catch date (dd/mm/yyyy)")
		fmt.Println("day(dd)")
		fmt.Scanln(&poke[*n].date[0])
		fmt.Println("Month(mm)")
		fmt.Scanln(&poke[*n].date[1])
		fmt.Println("Year(yyyy)")
		fmt.Scanln(&poke[*n].date[2])
		
		fmt.Println()
		*n++
		a++
	}
	fmt.Println("Pokemon data successfully input")
}

func menentukanbox(b int)int {

	if b > 30 {
		b = b - 30
		return 1+menentukanbox(b)
	}else if b<=29{
		return 0
	}else {
		return 1
	}
	return 0
	
}


func delete(poke *arrpoke, n *int) {
	var temp arrpoke
	var i,j int
	var input int
	var t bool
	
	fmt.Println("Input all the pokemon data(number,name,level...) that will be deleted")
	fmt.Println("If you dont remember all the data")
	fmt.Println("then you can search all the data that match 1 keyword")
	fmt.Println()
	fmt.Println("Input 1 (if you need all the data that match 1 keyword)")
	fmt.Println("Input 2 (if you dont need the help data)")
	fmt.Println("Input :")
	fmt.Scanln(&input)
	if input<1 || input >2{
		fmt.Println("Please input 1 or 2")
		fmt.Scanln(&input)
	}
	if input == 1{
		fmt.Println()
		searchpokemon(*poke,*n,&t)
		for t == false {
			fmt.Println()
			fmt.Println("Please input the correct keyword")
			searchpokemon(*poke,*n,&t)
		}
	}
	
	fmt.Println("Input the data below to delete the data: " )
	fmt.Println("1. Number:")
	fmt.Scanln(&temp[0].number)
	fmt.Println("2. Name:")
	fmt.Scanln(&temp[0].name)
	fmt.Println("3. Level:")
	fmt.Scanln(&temp[0].level)
	fmt.Println("4. Gender (M/F):")
	fmt.Scanln(&temp[0].gender)
	for temp[0].gender != "M" && temp[0].gender != "F" {
		fmt.Println("4. Gender (M/F):")
		fmt.Scanln(&temp[0].gender)
	}
	fmt.Println("5. Type:")
	fmt.Scanln(&temp[0].typee)
	fmt.Println("6. Tera type:")
	fmt.Scanln(&temp[0].tera)
	fmt.Println("7. HP:")
	fmt.Scanln(&temp[0].hp)
	fmt.Println("8. Attack:")
	fmt.Scanln(&temp[0].atk)
	fmt.Println("9. Defense:")
	fmt.Scanln(&temp[0].def)
	fmt.Println("10. Speed:")
	fmt.Scanln(&temp[0].spd)
	fmt.Println("11. Sp.Atk:")
	fmt.Scanln(&temp[0].spatk)
	fmt.Println("12. Sp.Def:")
	fmt.Scanln(&temp[0].spdef)
	
	fmt.Println("13. Ability:")
	fmt.Scanln(&temp[0].ability)
	fmt.Println("14. Held Item:")
	fmt.Scanln(&temp[0].held)
	fmt.Println("15. Move 1:")
	fmt.Scanln(&temp[0].move[0])
	fmt.Println("16. Move 2:")
	fmt.Scanln(&temp[0].move[1])
	fmt.Println("17. Move 3:")
	fmt.Scanln(&temp[0].move[2])
	fmt.Println("18. Move 4:")
	fmt.Scanln(&temp[0].move[3])
	fmt.Println("19. Catch location:")
	fmt.Scanln(&temp[0].location)
	fmt.Println("20. Catch date: (dd/mm/yyyy)")
	fmt.Println("Catch date day: (dd)")
	fmt.Scanln(&temp[0].date[0])
	fmt.Println("Catch date month: (mm)")
	fmt.Scanln(&temp[0].date[1])
	fmt.Println("Catch date year: (yyyy)")
	fmt.Scanln(&temp[0].date[2])
	
	fmt.Println()

	idx := -1
	i=0
	for  i < *n && j!=-1{
		if poke[i] == temp[0] {
			idx = i
			j=1
		}
		i++
	}

	if idx != -1 {
		poke[i].number = 0
		poke[i].name = "0"
		poke[i].level = 0
		poke[i].gender = "0"
		poke[i].typee = "0"
		poke[i].tera = "0"
		poke[i].hp = 0
		poke[i].atk = 0
		poke[i].def = 0
		poke[i].spd = 0
		poke[i].spatk = 0
		poke[i].spdef = 0
		poke[i].ability = "0"
		poke[i].held = "0"
		poke[i].move[0] = "0"
		poke[i].move[1] = "0"
		poke[i].move[2] = "0"
		poke[i].move[3] = "0"
		poke[i].location = "0"
		poke[i].date[0] = 0
		poke[i].date[1] = 0
		poke[i].date[2] = 0
		
		for i := idx; i < *n-1; i++ {
			poke[i]=poke[i+1]
		}
		*n = *n - 1
		fmt.Println("Pokemon data successfully deleted")
	} else {
		fmt.Println("Pokemon data not found")
	}
}


func changepokedata(poke *arrpoke, n int) {
	var temp arrpoke
	var i,j int
	var input int
	var t bool

	fmt.Println("Input all the pokemon data(number,name,level...) that will be change")
	fmt.Println("If you dont remember all the data")
	fmt.Println("then you can search all the data that match 1 keyword")
	fmt.Println()
	fmt.Println("Input 1 if you need all the data that match 1 keyword")
	fmt.Println("Input 2 if you dont need the dont need help data")
	fmt.Println("Input :")
	fmt.Scanln(&input)
	if input<1 || input >2{
		fmt.Println("Please input 1 or 2")
		fmt.Scanln(&input)
	}
	if input == 1{
		fmt.Println()
		searchpokemon(*poke,n,&t)
		for t == false {
			fmt.Println()
			fmt.Println("Please input the correct keyword")
			searchpokemon(*poke,n,&t)
		}
	}
	fmt.Println("Input the data below to change the previous data: " )
	fmt.Println("1. Number:")
	fmt.Scanln(&temp[0].number)
	fmt.Println("2. Name:")
	fmt.Scanln(&temp[0].name)
	fmt.Println("3. Level:")
	fmt.Scanln(&temp[0].level)
	fmt.Println("4. Gender (M/F):")
	fmt.Scanln(&temp[0].gender)
	for temp[0].gender != "M" && temp[0].gender != "F" {
		fmt.Println("4. Gender (M/F):")
		fmt.Scanln(&temp[0].gender)
	}
	fmt.Println("5. Type:")
	fmt.Scanln(&temp[0].typee)
	fmt.Println("6. Tera type:")
	fmt.Scanln(&temp[0].tera)
	fmt.Println("7. HP:")
	fmt.Scanln(&temp[0].hp)
	fmt.Println("8. Attack:")
	fmt.Scanln(&temp[0].atk)
	fmt.Println("9. Defense:")
	fmt.Scanln(&temp[0].def)
	fmt.Println("10. Speed:")
	fmt.Scanln(&temp[0].spd)
	fmt.Println("11. Sp.Atk:")
	fmt.Scanln(&temp[0].spatk)
	fmt.Println("12. Sp.Def:")
	fmt.Scanln(&temp[0].spdef)
	
	fmt.Println("13. Ability:")
	fmt.Scanln(&temp[0].ability)
	fmt.Println("14. Held Item:")
	fmt.Scanln(&temp[0].held)
	fmt.Println("15. Move 1:")
	fmt.Scanln(&temp[0].move[0])
	fmt.Println("16. Move 2:")
	fmt.Scanln(&temp[0].move[1])
	fmt.Println("17. Move 3:")
	fmt.Scanln(&temp[0].move[2])
	fmt.Println("18. Move 4:")
	fmt.Scanln(&temp[0].move[3])
	fmt.Println("19. Catch location:")
	fmt.Scanln(&temp[0].location)
	fmt.Println("20. Catch date: (dd/mm/yyyy)")
	fmt.Println("Catch date day: (dd)")
	fmt.Scanln(&temp[0].date[0])
	fmt.Println("Catch date month: (mm)")
	fmt.Scanln(&temp[0].date[1])
	fmt.Println("Catch date year: (yyyy)")
	fmt.Scanln(&temp[0].date[2])

	idx := -1
	i=0
	for  i < n && j!=-1 {
		if poke[i] == temp[0] {
			idx = i
			j=1
		}
		i++
	}

	if idx != -1 {
		fmt.Println("Input to change the data")
		fmt.Println()

		fmt.Println("Number:")
		fmt.Scanln(&poke[idx].number)
		fmt.Println("Name:")
		fmt.Scanln(&poke[idx].name)
		fmt.Println("Level:")
		fmt.Scanln(&poke[idx].level)
		fmt.Println("Gender (M/F):")
		fmt.Scanln(&poke[idx].gender)
		for poke[idx].gender != "M" && poke[idx].gender != "F" {
			fmt.Println("Gender (M/F) :")
			fmt.Scanln(&poke[idx].gender)
		}
		fmt.Println("Type:")
		fmt.Scanln(&poke[idx].typee)
		fmt.Println("Tera type:")
		fmt.Scanln(&poke[idx].tera)
		fmt.Println("HP:")
		fmt.Scanln(&poke[idx].hp)
		fmt.Println("Attack:")
		fmt.Scanln(&poke[idx].atk)
		fmt.Println("Defense:")
		fmt.Scanln(&poke[idx].def)
		fmt.Println("Speed:")
		fmt.Scanln(&poke[idx].spd)
		fmt.Println("Sp.Atk:")
		fmt.Scanln(&poke[idx].spatk)
		fmt.Println("Sp.Def:")
		fmt.Scanln(&poke[idx].spdef)
		
		fmt.Println("Ability:")
		fmt.Scanln(&poke[idx].ability)
		fmt.Println("Held Item:")
		fmt.Scanln(&poke[idx].held)
		fmt.Println("Move 1:")
		fmt.Scanln(&poke[idx].move[0])
		fmt.Println("Move 2:")
		fmt.Scanln(&poke[idx].move[1])
		fmt.Println("Move 3:")
		fmt.Scanln(&poke[idx].move[2])
		fmt.Println("Move 4:")
		fmt.Scanln(&poke[idx].move[3])
		fmt.Println("Catch location:")
		fmt.Scanln(&poke[idx].location)
		fmt.Println("Catch date: (dd/mm/yyyy)")
		fmt.Println("Catch date day: (dd)")
		fmt.Scanln(&poke[idx].date[0])
		fmt.Println("Catch date month: (mm)")
		fmt.Scanln(&poke[idx].date[1])
		fmt.Println("Catch date year: (yyyy)")
		fmt.Scanln(&poke[idx].date[2])
		
		fmt.Println()
		fmt.Println("Pokemon data successfully changed")
	} else {
		fmt.Println("Pokemon data not found")
	}
}


func searchpokemon(poke arrpoke,n int,t *bool) {
	var temp arrpoke
	var  j int
	var input int
	var found bool

	fmt.Println("Choose the base data for searching: ")
	fmt.Println()
	fmt.Println("1. Number")
	fmt.Println("2. Name")
	fmt.Println("3. Level")
	fmt.Println("4. Gender")
	fmt.Println("5. Type")
	fmt.Println("6. Tera type")
	fmt.Println("7. HP")
	fmt.Println("8. Attack")
	fmt.Println("9. Defense")
	fmt.Println("10. Speed")
	fmt.Println("11. Sp.Atk")
	fmt.Println("12. SP.Def")
	fmt.Println("13. Ability")
	fmt.Println("14. Held Item")
	fmt.Println("15. Move")
	fmt.Println("16. Catch Location")
	fmt.Println("17. Catch Date")
	
	fmt.Println()
	fmt.Println("If you want to search speed then input 10")
	fmt.Println("Input :")
	fmt.Scanln(&input)
	for input < 1 || input > 17 {
		fmt.Println("Please input between 1 until 18")
		fmt.Println("Input :")
		fmt.Scanln(&input)
	}
	
	
	found = false
	if input == 1 {
		fmt.Println("Please input the number")
		fmt.Scanln(&temp[0].number)
		for j = 0; j < n; j++ {
			if poke[j].number == temp[0].number {
				fmt.Println(poke[j])
				found = true
				*t=true
			}
			
		}

	} else if input == 2 {
		fmt.Println("Please input the name")
		fmt.Scanln(&temp[0].name)
		for j = 0; j < n; j++ {
			if poke[j].name == temp[0].name {
				fmt.Println(poke[j])
				found = true
				*t=true
			}
		}

	} else if input == 3 {
		fmt.Println("Please input the level")
		fmt.Scanln(&temp[0].level)
		for j = 0; j < n; j++ {
			if poke[j].level == temp[0].level {
				fmt.Println(poke[j])
				found = true
				*t=true
			}
		}

	} else if input == 4 {
		fmt.Println("Please input the gender (M/F)")
		fmt.Scanln(&temp[0].gender)
		for temp[0].gender != "M" && temp[0].gender != "F" {
			fmt.Println("Please input the replacement data of gender (M/F)")
			fmt.Scanln(&temp[0].gender)
		}
		for j = 0; j < n; j++ {
			if poke[j].gender == temp[0].gender {
				fmt.Println(poke[j])
				found = true
				*t=true
			}
		}

	} else if input == 5 {
		fmt.Println("Please input the Type")
		fmt.Scanln(&temp[0].typee)
		for j = 0; j < n; j++ {
			if poke[j].typee == temp[0].typee {
				fmt.Println(poke[j])
				found = true
				*t=true
			}
		}

	} else if input == 6 {
		fmt.Println("Please input the Tera type")
		fmt.Scanln(&temp[0].tera)
		for j = 0; j < n; j++ {
			if poke[j].tera == temp[0].tera {
				fmt.Println(poke[j])
				found = true
				*t=true
			}
		}

	} else if input == 7 {
		fmt.Println("Please input the HP")
		fmt.Scanln(&temp[0].hp)
		for j = 0; j < n; j++ {
			if poke[j].hp == temp[0].hp {
				fmt.Println(poke[j])
				found = true
				*t=true
			}
		}

	} else if input == 8 {
		fmt.Println("Please input the Attack")
		fmt.Scanln(&temp[0].atk)
		for j = 0; j < n; j++ {
			if poke[j].atk == temp[0].atk {
				fmt.Println(poke[j])
				found = true
				*t=true
			}
		}


	} else if input == 9 {
		fmt.Println("Please input the Defense")
		fmt.Scanln(&temp[0].def)
		for j = 0; j < n; j++ {
			if poke[j].def == temp[0].def {
				fmt.Println(poke[j])
				found = true
				*t=true
			}
		}


	} else if input == 10 {
		fmt.Println("Please input the Speed")
		fmt.Scanln(&temp[0].spd)
		for j = 0; j < n; j++ {
			if poke[j].spd == temp[0].spd {
				fmt.Println(poke[j])
				found = true
				*t=true
			}
		}


	} else if input == 11 {
		fmt.Println("Please input the Sp.Atk")
		fmt.Scanln(&temp[0].spatk)
		for j = 0; j < n; j++ {
			if poke[j].spatk == temp[0].spatk {
				fmt.Println(poke[j])
				found = true
				*t=true
			}
		}

	} else if input == 12 {
		fmt.Println("Please input the Sp.Def")
		fmt.Scanln(&temp[0].spdef)
		for j = 0; j < n; j++ {
			if poke[j].spdef == temp[0].spdef {
				fmt.Println(poke[j])
				found = true
				*t=true
			}
		}

	}else if input == 13 {
		fmt.Println("Please input the Ability")
		fmt.Scanln(&temp[0].ability)
		for j = 0; j < n; j++ {
			if poke[j].ability == temp[0].ability {
				fmt.Println(poke[j])
				found = true
				*t=true
			}
		}

	}else if input == 14 {
		fmt.Println("Please input the Held Item")
		fmt.Scanln(&temp[0].held)
		for j = 0; j < n; j++ {
			if poke[j].held == temp[0].held {
				fmt.Println(poke[j])
				found = true
				*t=true
			}
		}

	}else if input == 15 {
		fmt.Println("Please input the Pokemon Move")
		fmt.Scanln(&temp[0].move[0])
		for j = 0; j < n; j++ {
			if poke[j].move[0] == temp[0].move[0] {
				fmt.Println(poke[j])
				found = true
				*t=true
			}else if poke[j].move[1] == temp[0].move[0] {
				fmt.Println(poke[j])
				found = true
				*t=true
			}else if poke[j].move[2] == temp[0].move[0] {
				fmt.Println(poke[j])
				found = true
				*t=true
			}else if poke[j].move[3] == temp[0].move[0] {
				fmt.Println(poke[j])
				found = true
				*t=true
			}
		}

	}else if input == 16 {
		fmt.Println("Please input the Catch location")
		fmt.Scanln(&temp[0].location)
		for j = 0; j < n; j++ {
			if poke[j].location == temp[0].location {
				fmt.Println(poke[j])
				found = true
				*t=true
			}
		}
	
	}else  {
		fmt.Println("Please input the Catch date")
		fmt.Println("day :(dd)")
		fmt.Scanln(&temp[0].date[0])
		fmt.Println("month :(mm)")
		fmt.Scanln(&temp[0].date[1])
		fmt.Println("year :(yyyy)")
		fmt.Scanln(&temp[0].date[2])
		for j = 0; j < n; j++ {
			if poke[j].date[0] == temp[0].date[0] && poke[j].date[1] == temp[0].date[1]&& poke[j].date[2] == temp[0].date[2] {
				fmt.Println(poke[j])
				found = true
				*t=true
			}
		}

	}
	if !found {
		fmt.Println("No data matched")
		*t=false
	}
}

func listpokemon(poke arrpoke, n int) {
	var temp arrpoke
	var input int
	var i, idx, j int

	fmt.Println("Choose on how to show pokemon list ")
	fmt.Println()
	fmt.Println("1. Number")
	fmt.Println("2. Name")
	fmt.Println("3. Level")
	fmt.Println("4. Gender")
	fmt.Println("5. Type")
	fmt.Println("6. Tera type")
	fmt.Println("7. HP")
	fmt.Println("8. Attack")
	fmt.Println("9. Defense")
	fmt.Println("10. Speed")
	fmt.Println("11. Sp.Atk")
	fmt.Println("12. SP.Def")
	fmt.Println("13. Ability")
	fmt.Println("14. Held Item")
	fmt.Println("15. Catch Location")
	fmt.Println("16. Catch Date")
	fmt.Println("17. Default")
	fmt.Println()
	fmt.Println("If you want to list base on number then input 1")
	fmt.Println("Input :")
	fmt.Scanln(&input)
	for input <1 || input>17 {
		fmt.Println("Please input between 1-17")
		fmt.Scanln(&input)
	}

	if input == 1 {
		fmt.Println("List base on number")
		i = 1
		for i <= n-1 {
			idx = i - 1
			j = i
			for j < n {
				if poke[idx].number > poke[j].number {
					idx = j
				}
				j = j + 1
			}
			temp[0] = poke[idx]
			poke[idx] = poke[i-1]
			poke[i-1] = temp[0]
			i = i + 1
		}
		print(poke,n)

		} else if input == 2 {
		fmt.Println("List based on name")
		for i = 0; i < n-1; i++ {
			for j = 0; j < n-i-1; j++ {
				if poke[j].name > poke[j+1].name {
					temp[0] = poke[j]
					poke[j] = poke[j+1]
					poke[j+1] = temp[0]
				}
			}
		}
		print(poke, n)
	} else if input == 3 {
		fmt.Println("List base on level")
		i = 1
		for i <= n-1 {
			idx = i - 1
			j = i
			for j < n {
				if poke[idx].level > poke[j].level {
					idx = j
				}
				j = j + 1
			}
			temp[0] = poke[idx]
			poke[idx] = poke[i-1]
			poke[i-1] = temp[0]
			i = i + 1
		}
		print(poke,n)
	} else if input == 4 {
		fmt.Println("List base on gender")
		for i = 0; i < n-1; i++ {
			for j = 0; j < n-i-1; j++ {
				if poke[j].gender > poke[j+1].gender {
					temp[0] = poke[j]
					poke[j] = poke[j+1]
					poke[j+1] = temp[0]
				}
			}
		}
		print(poke, n)
	} else if input == 5 {
		fmt.Println("List base on type")
		for i = 0; i < n-1; i++ {
			for j = 0; j < n-i-1; j++ {
				if poke[j].typee > poke[j+1].typee {
					temp[0] = poke[j]
					poke[j] = poke[j+1]
					poke[j+1] = temp[0]
				}
			}
		}
		print(poke, n)
	} else if input == 6 {
		fmt.Println("List base on Tera type")
		for i = 0; i < n-1; i++ {
			for j = 0; j < n-i-1; j++ {
				if poke[j].tera > poke[j+1].tera {
					temp[0] = poke[j]
					poke[j] = poke[j+1]
					poke[j+1] = temp[0]
				}
			}
		}
		print(poke, n)
		
	} else if input == 7 {
		fmt.Println("List base on hp")
		i = 1
		for i <= n-1 {
			idx = i - 1
			j = i
			for j < n {
				if poke[idx].hp > poke[j].hp {
					idx = j
				}
				j = j + 1
			}
			temp[0] = poke[idx]
			poke[idx] = poke[i-1]
			poke[i-1] = temp[0]
			i = i + 1
		}
		print(poke,n)
	} else if input == 8 {
		fmt.Println("List base on attack")
		i = 1
		for i <= n-1 {
			idx = i - 1
			j = i
			for j < n {
				if poke[idx].atk > poke[j].atk {
					idx = j
				}
				j = j + 1
			}
			temp[0] = poke[idx]
			poke[idx] = poke[i-1]
			poke[i-1] = temp[0]
			i = i + 1
		}
		print(poke,n)
	} else if input == 9 {
		fmt.Println("List base on defense")
		i = 1
		for i <= n-1 {
			idx = i - 1
			j = i
			for j < n {
				if poke[idx].def > poke[j].def {
					idx = j
				}
				j = j + 1
			}
			temp[0] = poke[idx]
			poke[idx] = poke[i-1]
			poke[i-1] = temp[0]
			i = i + 1
		}
		print(poke,n)
	} else if input == 10 {
		fmt.Println("List base on speed")
		i = 1
		for i <= n-1 {
			idx = i - 1
			j = i
			for j < n {
				if poke[idx].spd > poke[j].spd {
					idx = j
				}
				j = j + 1
			}
			temp[0] = poke[idx]
			poke[idx] = poke[i-1]
			poke[i-1] = temp[0]
			i = i + 1
		}
		print(poke,n)
	} else if input == 11 {
		fmt.Println("List base on sp.atk")
		i = 1
		for i <= n-1 {
			idx = i - 1
			j = i
			for j < n {
				if poke[idx].spatk > poke[j].spatk {
					idx = j
				}
				j = j + 1
			}
			temp[0] = poke[idx]
			poke[idx] = poke[i-1]
			poke[i-1] = temp[0]
			i = i + 1
		}
		print(poke,n)
		
	} else if input == 12{
		fmt.Println("List base on sp.def")
		i = 1
		for i <= n-1 {
			idx = i - 1
			j = i
			for j < n {
				if poke[idx].spdef > poke[j].spdef {
					idx = j
				}
				j = j + 1
			}
			temp[0] = poke[idx]
			poke[idx] = poke[i-1]
			poke[i-1] = temp[0]
			i = i + 1
		}
	}else if input == 13 {
		fmt.Println("List base on Ability")
		for i = 0; i < n-1; i++ {
			for j = 0; j < n-i-1; j++ {
				if poke[j].ability > poke[j+1].ability {
					temp[0] = poke[j]
					poke[j] = poke[j+1]
					poke[j+1] = temp[0]
				}
			}
		}
		print(poke, n)
	}else if input == 14 {
		fmt.Println("List base on Held item")
		for i = 0; i < n-1; i++ {
			for j = 0; j < n-i-1; j++ {
				if poke[j].held > poke[j+1].held {
					temp[0] = poke[j]
					poke[j] = poke[j+1]
					poke[j+1] = temp[0]
				}
			}
		}
		print(poke, n)
	}else if input == 15 {
		fmt.Println("List base on catch location")
		for i = 0; i < n-1; i++ {
			for j = 0; j < n-i-1; j++ {
				if poke[j].location > poke[j+1].location {
					temp[0] = poke[j]
					poke[j] = poke[j+1]
					poke[j+1] = temp[0]
				}
			}
		}
		print(poke, n)
	}else if input == 16 {
		fmt.Println("List base on catch date")
		i = 1
		for i <= n-1 {
			idx = i - 1
			j = i
			for j < n {
				if (poke[idx].date[0])+((poke[idx].date[1])*30)+((poke[idx].date[2])*365) > (poke[j].date[0])+((poke[j].date[1])*30)+((poke[j].date[2])*365) {
					idx = j
				}
				j = j + 1
			}
			temp[0] = poke[idx]
			poke[idx] = poke[i-1]
			poke[i-1] = temp[0]
			i = i + 1
		}
		print(poke,n)
	}else {
		print(poke,n)
	}
	
}

func print(poke arrpoke,n int){
	var a,masukan,box int
	
	box = n / 30
	if n%30 != 0 {
		box++
	}

	fmt.Println("There are", box, "box")
	fmt.Println()
	fmt.Println("box 1")
	for a < n && a < 30 {
		fmt.Println(poke[a])
		a++
	}

	masukan = 1
	for masukan != 0&& a<n {
		fmt.Println()
		fmt.Println("Input 1 for next box, Input 2 for previous box, or Input 0 for exit")
		fmt.Scanln(&masukan)
		if masukan == 1 && a < n {
			fmt.Println()
			fmt.Println("box", (a/30)+1)
			for i := 0; i < 30 && a < n; i++ {
				fmt.Println(poke[a])
				a++
			}
		} else if masukan == 2 && a >= 30 {
			if a == 30 {
				fmt.Println("There is no previous page")
			} else {
				a = a - 60
				fmt.Println()
				fmt.Println("box", (a/30)+1)
				for i := 0; i < 30 && a < n; i++ {
					fmt.Println(poke[a])
					a++
				}
			}
		}
	}	

}
