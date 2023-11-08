package main

import "fmt"

type IRouteBuilder interface {
	buildRoute()
}

type carRoute struct {
	IRouteBuilder
}

type cycleRoute struct {
	IRouteBuilder
}

type walkingRoute struct {
	IRouteBuilder
}

func (route *carRoute) buildRoute() {
	fmt.Println("Building car route")
}

func (route *cycleRoute) buildRoute() {
	fmt.Println("Building cycle route")
}

func (route *walkingRoute) buildRoute() {
	fmt.Println("Building walking route")
}

func main() {
	fmt.Println("Rohit")
}
