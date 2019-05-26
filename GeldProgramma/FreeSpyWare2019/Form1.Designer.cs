namespace FreeSpyWare2
{
    partial class GratisGeld
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(GratisGeld));
            this.Titel = new System.Windows.Forms.Label();
            this.Bedrag = new System.Windows.Forms.Label();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.IBAN = new System.Windows.Forms.Label();
            this.textBox2 = new System.Windows.Forms.TextBox();
            this.button = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // Titel
            // 
            this.Titel.AutoSize = true;
            this.Titel.BackColor = System.Drawing.Color.Transparent;
            this.Titel.Font = new System.Drawing.Font("Microsoft Sans Serif", 20.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Titel.Location = new System.Drawing.Point(39, 30);
            this.Titel.Name = "Titel";
            this.Titel.Size = new System.Drawing.Size(576, 31);
            this.Titel.TabIndex = 0;
            this.Titel.Text = "Maak nu snel die miljoenen over naar uw bank!";
            this.Titel.Click += new System.EventHandler(this.Titel_Click);
            // 
            // Bedrag
            // 
            this.Bedrag.AutoSize = true;
            this.Bedrag.BackColor = System.Drawing.Color.Transparent;
            this.Bedrag.Cursor = System.Windows.Forms.Cursors.No;
            this.Bedrag.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Bedrag.Location = new System.Drawing.Point(42, 143);
            this.Bedrag.Name = "Bedrag";
            this.Bedrag.Size = new System.Drawing.Size(123, 20);
            this.Bedrag.TabIndex = 1;
            this.Bedrag.Text = "Bedrag in Euro :";
            // 
            // textBox1
            // 
            this.textBox1.BackColor = System.Drawing.SystemColors.Window;
            this.textBox1.Location = new System.Drawing.Point(184, 143);
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(216, 20);
            this.textBox1.TabIndex = 2;
            this.textBox1.TextChanged += new System.EventHandler(this.TextBox1_TextChanged);
            // 
            // IBAN
            // 
            this.IBAN.AutoSize = true;
            this.IBAN.BackColor = System.Drawing.Color.Transparent;
            this.IBAN.Cursor = System.Windows.Forms.Cursors.No;
            this.IBAN.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.IBAN.Location = new System.Drawing.Point(42, 199);
            this.IBAN.Name = "IBAN";
            this.IBAN.Size = new System.Drawing.Size(82, 20);
            this.IBAN.TabIndex = 3;
            this.IBAN.Text = "Uw IBAN :";
            // 
            // textBox2
            // 
            this.textBox2.BackColor = System.Drawing.SystemColors.Window;
            this.textBox2.Location = new System.Drawing.Point(184, 199);
            this.textBox2.Name = "textBox2";
            this.textBox2.Size = new System.Drawing.Size(216, 20);
            this.textBox2.TabIndex = 4;
            // 
            // button
            // 
            this.button.BackColor = System.Drawing.Color.Gainsboro;
            this.button.Location = new System.Drawing.Point(184, 248);
            this.button.Name = "button";
            this.button.Size = new System.Drawing.Size(75, 23);
            this.button.TabIndex = 5;
            this.button.Text = "Verstuur!";
            this.button.UseVisualStyleBackColor = false;
            this.button.Click += new System.EventHandler(this.Button_Click);
            // 
            // GratisGeld
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("$this.BackgroundImage")));
            this.ClientSize = new System.Drawing.Size(630, 508);
            this.Controls.Add(this.button);
            this.Controls.Add(this.textBox2);
            this.Controls.Add(this.IBAN);
            this.Controls.Add(this.textBox1);
            this.Controls.Add(this.Bedrag);
            this.Controls.Add(this.Titel);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "GratisGeld";
            this.Text = "Gratis geld overmaker 2019";
            this.Load += new System.EventHandler(this.GratisGeld_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label Titel;
        private System.Windows.Forms.Label Bedrag;
        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.Label IBAN;
        private System.Windows.Forms.TextBox textBox2;
        private System.Windows.Forms.Button button;
    }
}

