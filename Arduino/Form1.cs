using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO.Ports;

namespace Arduino
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

            string[] portNames = SerialPort.GetPortNames();

            // Add the port names to the ComboBox
            foreach (string portName in portNames)
            {
                comboBox1.Items.Add(portName);
            }





            serialPort1.BaudRate = 9600;
           
            button2.Enabled = false;
        }

        private void button1_Click(object sender, EventArgs e)
        {



            try
            {
           
                string selectedPortName = comboBox1.SelectedItem.ToString();

                serialPort1.PortName = selectedPortName;
                serialPort1.Open();


                serialPort1.Write("1");
                label1.Text = "LED ON";
                button1.Enabled = false;
                button2.Enabled = true;
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }






        }

        private void button2_Click(object sender, EventArgs e)
        {
            serialPort1.Write("0");
            label1.Text = "LED OFF";
            button1.Enabled = true;
            button2.Enabled = false;
            serialPort1.Close();
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            if(serialPort1.IsOpen==true)
            {
                button2.PerformClick();
                serialPort1.Close();
                
            }
        }
    }
}
