# Introduction to Jython

from javax.swing import JFrame, JLabel

frame = JFrame("Hello, Jython!", 
                defaultCloseOperation = JFrame.EXIT_ON_CLOSE,
                size = (200, 200)
              )
label = JLabel("Hello, Jython")

frame.add(label)
frame.show()


