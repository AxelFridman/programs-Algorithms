# 07-eventReactive

library(shiny)

ui <- fluidPage(
  sliderInput(inputId = "num", 
              label = "Choose a number", 
              value = 25, min = 1, max = 100),
  textInput(inputId = "title", 
            label = "Write a title",
            value = "Histogram of Random Normal Values"),
  actionButton(inputId = "go", 
               label = "Update"),
  plotOutput("hist")
)

server <- function(input, output) {
  data <- reactive({
    rnorm(input$num) 
  })
  
  titulo <- eventReactive(input$go, input$title)
  
  output$hist <- renderPlot({
    hist(data(), main = titulo())
  })
}

shinyApp(ui = ui, server = server)