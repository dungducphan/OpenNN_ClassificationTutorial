#include <iostream>

#include <opennn.h>
#include <data_set.h>
#include <instances.h>
#include <variables.h>
#include <neural_network.h>


int main() {

    /*
     * DATA SET
     */

    OpenNN::DataSet myDataSet;
    myDataSet.set_data_file_name("banknotes.dat");
    myDataSet.set_separator("Comma");
    myDataSet.load_data();

    OpenNN::Instances* instances_pointer = myDataSet.get_instances_pointer();
    instances_pointer->split_random_indices();
    const OpenNN::Vector<OpenNN::Statistics<double> > input_statistics = myDataSet.scale_inputs_minimum_maximum();

    /*
     * Regression problem required target scaling.
     * Classification problem does NOT required target scaling.
     * The following line only calculates the target statistics.
     */
    const OpenNN::Vector<OpenNN::Statistics<double> > target_statistics = myDataSet.scale_targets_minimum_maximum();

    OpenNN::Variables* variable_pointer = myDataSet.get_variables_pointer();
    const size_t inputs_number = variable_pointer->count_inputs_number();
    const size_t targets_number = variable_pointer->count_targets_number();

    std::cout << "Inputs number: " << inputs_number << "." << std::endl;
    std::cout << "Target number: " << targets_number << "." << std::endl;


    /*
     * NEURAL NET ARCHITECTURE
     */

    OpenNN::NeuralNetwork myNeuralNet = OpenNN::NeuralNetwork(inputs_number, 9, targets_number);
    myNeuralNet.construct_scaling_layer();

    OpenNN::ScalingLayer* scalingLayer = myNeuralNet.get_scaling_layer_pointer();
    scalingLayer->set_statistics(input_statistics);
    scalingLayer->set_scaling_method(OpenNN::ScalingLayer::NoScaling);

    myNeuralNet.construct_probabilistic_layer();

    OpenNN::ProbabilisticLayer* probabilisticLayer = myNeuralNet.get_probabilistic_layer_pointer();
    probabilisticLayer->set_probabilistic_method(OpenNN::ProbabilisticLayer::Probability);


    /*
     * Loss Index Metrics
     */

    OpenNN::LossIndex lossIndex(&myNeuralNet, &myDataSet);
    lossIndex.set_error_type("NORMALIZED_SQUARED_ERROR");
    lossIndex.set_regularization_type(OpenNN::LossIndex::NEURAL_PARAMETERS_NORM);


    /*
     * Training Strategy (MINIMIZATION PROBLEM at hand)
     */

    OpenNN::TrainingStrategy trainingStrategy(&lossIndex);
    trainingStrategy.set_main_type(OpenNN::TrainingStrategy::QUASI_NEWTON_METHOD);

    OpenNN::QuasiNewtonMethod* quasiNewtonMethod = trainingStrategy.get_quasi_Newton_method_pointer();
    quasiNewtonMethod->set_maximum_iterations_number(1000);
    quasiNewtonMethod->set_display_period(100);

    trainingStrategy.perform_training();


    /*
     * Training Performance Test.
     * Quantify the performance of the neural net in classification problem at hand.
     */

    OpenNN::TestingAnalysis testingAnalysis(&myNeuralNet, &myDataSet);
    OpenNN::Matrix<size_t> confusionMatrix = testingAnalysis.calculate_confusion();


    /*
     * Model deployment.
     */

    scalingLayer->set_scaling_method(OpenNN::ScalingLayer::MinimumMaximum);

    myNeuralNet.save_expression("expression.txt");
    myNeuralNet.save_expression_python("expression.py");
    myNeuralNet.save_expression_R("expression.r");

    return 0;
}