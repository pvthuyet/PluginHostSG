/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
PluginHostSGAudioProcessorEditor::PluginHostSGAudioProcessorEditor (PluginHostSGAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setLookAndFeel(&lookAndfeel);

    addAndMakeVisible(scanButton);
    scanButton.setButtonText("Scan");

    scanButton.onClick = []() {
      juce::AlertWindow::showMessageBoxAsync(juce::MessageBoxIconType::InfoIcon, "Test", "Hello world!");
    };

    setSize (1024, 720);
}

PluginHostSGAudioProcessorEditor::~PluginHostSGAudioProcessorEditor()
{
    setLookAndFeel(nullptr);
}

//==============================================================================
void PluginHostSGAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
}

void PluginHostSGAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    scanButton.setBounds(0, 0, 100, 30);
}
