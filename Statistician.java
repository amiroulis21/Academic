
public class Statistician {
    private int length;
    private double mean;
    private double max;
    private double min;
    private double sum;


    public Statistician() {
         length = 0;
         mean = 0;
         max = Double.NaN;
         min = Double.NaN;
         sum = 0;
    }

    public void addAll(Statistician addend) {
        try {
            length += addend.length;
            sum += addend.sum;
            mean = sum / (double) length;
            if (addend.min < min) {
                min = addend.min;
            }
            if (addend.max > max) {
                max = addend.max;
            }
        } catch (NullPointerException e) {
            System.out.println("This Statistician is null");
        }
    }

    public void clear() {
        length = 0;
        mean = 0;
        sum = 0;
        max = Double.NaN;
        min = Double.NaN;
    }
    public boolean equals(Object obj) {
        if (obj instanceof Statistician) {
            Statistician candidate = (Statistician) obj;
            return candidate.length() == length() && candidate.mean() == mean() && candidate.maximum() == maximum()
                    && candidate.minimum() == minimum() && candidate.sum() == sum();
        }
        return false;
    }
    public int length() {
        return length;
    }
    public double maximum() {
        return max;
    }
    public double mean() {
        return mean;
    }
    public double minimum() {
        return min;
    }
    public void next(double number) {
        sum += number;
        length++;
        mean = sum/(double)length;
        if (length == 1) {
            max = number;
            min = number;
        } else if (max < number) {
            max = number;
        } else if (min > number) {
            min = number;
        }
    }

        public double sum() {
            return sum;
        }
        public static Statistician union (Statistician s1, Statistician s2){
        if (s1 == null || s2 == null) {
            throw new NullPointerException("One or more arguments are null");
        }
            Statistician s3 = new Statistician();
            s3.length = s1.length + s2.length;
            s3.sum = s1.sum + s2.sum;
            s3.mean = s3.sum/(double)s3.length;
            if(s1.min < s2.min) {
                s3.min = s1.min;
            }
            else {
                s3.min = s2.min;
            }
            if (s1.max > s2.max) {
                s3.max = s1.max;
            }
            else {
                s3.max = s2.max;
            }
            return s3;
        }
}

