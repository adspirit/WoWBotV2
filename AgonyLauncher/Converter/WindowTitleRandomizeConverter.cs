﻿using AgonyLauncher.Utils;
using System;
using System.Globalization;
using System.Windows.Data;

namespace AgonyLauncher.Converter
{
    internal class WindowTitleRandomizeConverter : IValueConverter
    {
        public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
        {
            var length = RandomHelper.Random.Next(8, 21);
            return RandomHelper.RandomString(length);
        }

        public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
        {
            throw new NotImplementedException();
        }
    }
}