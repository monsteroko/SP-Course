using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using Windows.Foundation;
using Windows.Foundation.Collections;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Controls.Primitives;
using Windows.UI.Xaml.Data;
using Windows.UI.Xaml.Input;
using Windows.UI.Xaml.Media;
using Windows.UI.Xaml.Navigation;

// Документацию по шаблону элемента "Пустая страница" см. по адресу https://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x419

namespace Lab7
{
    /// <summary>
    /// Пустая страница, которую можно использовать саму по себе или для перехода внутри фрейма.
    /// </summary>
    public sealed partial class MainPage : Page
    {
        static DependencyObject FindChildByName(DependencyObject from, string name)
        {
            int count = VisualTreeHelper.GetChildrenCount(from);

            for (int i = 0; i < count; i++)
            {
                var child = VisualTreeHelper.GetChild(from, i);
                if (child is FrameworkElement && ((FrameworkElement)child).Name == name)
                    return child;

                var result = FindChildByName(child, name);
                if (result != null)
                    return result;
            }

            return null;
        }
        private Button Button3;
        private Button Button31;
        private Button Button3_Copy1;
        private ComboBox CB1;
        private ComboBox CB2;
        private ComboBox CB1_Copy;
        private ComboBox CB2_Copy;
        private ComboBox CB1_Copy1;
        private ComboBox CB2_Copy1;
        private TextBox TB1;
        private TextBox TB2;
        private TextBox TB1_Copy;
        private TextBox TB2_Copy;
        private TextBox TB1_Copy1;
        private TextBox TB2_Copy1;
        public MainPage()
        {
            this.InitializeComponent();
        }
        
        private void Button1_Click(object sender, RoutedEventArgs e)
        {
            MainHub.ScrollToSection(Hub2);
        }

        private void Button2_Click(object sender, RoutedEventArgs e)
        {
            MainHub.ScrollToSection(Hub3);
        }

        private void Button3_Click(object sender, RoutedEventArgs e)
        {
            double a;
            if (!Double.TryParse(TB1.Text, out a))
            {
                TB2.Text = "Error!";
                return;
            }
            switch (CB1.SelectedIndex)
            {
                case 0:
                    break;
                case 1:
                    a = a * 1000;
                    break;
                case 2:
                    a = a / 1000;
                    break;
            }
            switch (CB2.SelectedIndex)
            {
                case 0:
                    TB2.Text = (a * 2, 204).ToString();
                    break;
                case 1:
                    TB2.Text = (a * 35, 274).ToString();
                    break;
            }
        }

        private void Page_Loaded(object sender, RoutedEventArgs e)
        {
            Button3 = (Button)FindChildByName(this, "Button3");
            Button31 = (Button)FindChildByName(this, "Button31");
            Button3_Copy1 = (Button)FindChildByName(this, "Button3_Copy1");
            CB1 = (ComboBox)FindChildByName(this, "CB1");
            CB2 = (ComboBox)FindChildByName(this, "CB2");
            CB1_Copy = (ComboBox)FindChildByName(this, "CB1_Copy");
            CB2_Copy = (ComboBox)FindChildByName(this, "CB2_Copy");
            CB1_Copy1 = (ComboBox)FindChildByName(this, "CB1_Copy1");
            CB2_Copy1 = (ComboBox)FindChildByName(this, "CB2_Copy1");
            TB1 = (TextBox)FindChildByName(this, "TB1");
            TB2 = (TextBox)FindChildByName(this, "TB2");
            TB1_Copy = (TextBox)FindChildByName(this, "TB1_Copy");
            TB2_Copy = (TextBox)FindChildByName(this, "TB2_Copy");
            TB1_Copy1 = (TextBox)FindChildByName(this, "TB1_Copy1");
            TB2_Copy1 = (TextBox)FindChildByName(this, "TB2_Copy1");
            CB1.SelectedIndex = 0;
            CB2.SelectedIndex = 0;
            CB1_Copy.SelectedIndex = 0;
            CB2_Copy.SelectedIndex = 0;
            CB1_Copy1.SelectedIndex = 0;
            CB2_Copy1.SelectedIndex = 0;
        }

        private void Button31_Click(object sender, RoutedEventArgs e)
        {
            double a;
            if (!Double.TryParse(TB1_Copy.Text, out a))
            {
                TB2_Copy.Text = "Error!";
                return;
            }
            switch (CB1_Copy.SelectedIndex)
            {
                case 0:
                    break;
                case 1:
                    a = a / 1000;
                    break;
                case 2:
                    a = a / 10000;
                    break;
            }
            switch (CB2_Copy.SelectedIndex)
            {
                case 0:
                    TB2_Copy.Text = (a * 3280,84).ToString();
                    break;
                case 1:
                    TB2_Copy.Text = (a * 0,621).ToString();
                    break;
                case 2:
                    TB2_Copy.Text = (a * 39370, 1).ToString();
                    break;
                case 3:
                    TB2_Copy.Text = (a * 1093, 61).ToString();
                    break;
            }
        }

        private void Button3_Copy1_Click(object sender, RoutedEventArgs e)
        {
            double a;
            if (!Double.TryParse(TB1_Copy1.Text, out a))
            {
                TB2_Copy1.Text = "Error!";
                return;
            }
            switch (CB1_Copy1.SelectedIndex)
            {
                case 0:
                    break;
                case 1:
                    a = a * 1000000;
                    break;
                case 2:
                    a = a * 1000;
                    break;
            }
            switch (CB2_Copy1.SelectedIndex)
            {
                case 0:
                    TB2_Copy1.Text = (a * 264, 172).ToString();
                    break;
                case 1:
                    TB2_Copy1.Text = (a * 2113, 38).ToString();
                    break;
            }
        }
    }
}
