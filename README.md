# MikulusVST
VST Plugin for Mikulus OSC Connection.
DAWのビート情報をMikulusへ送るVSTインストゥルメントです。

# インストール方法

1. MikulusVST.zipを解凍
2. `Win32/MikulusVST.vst3`を`C:\Program Files (x86)\Common Files\VST3\`フォルダにコピー
3. `x64/MikulusVST.vst3`を`C:\Program Files\Common Files\VST3\`フォルダにコピー
4. DAWを再起動するか、プラグインを再読込

# 動作確認済みのDAW
- FL Studio
  `Plugin Database/Installed/VST3/Mikulus VST3`をチャンネルラックに追加すると動きます。
- Cubase
  インストゥルメントトラックとして追加すると動きます。

# 仕様（Mikulus開発者向け）
ローカルマシンの3939/udpに以下のOSC信号を送信します。

- `/VST/BPM <BPM値:double>`
  BPMが変わったときに送ります。
- `/VST/OnBeat <BPM値:double>`
  ４分音符のタイミングで送ります。
- `/VST/OnBar <BPM値:double>`
  小節頭のタイミングで送ります。
  （小節頭では、`/VST/OnBeat`と同時に送ります）

# Development Dependency
- VST SDK 3.6.6 (please extract to ./vst_sdk)
- oscpack 1.1.0 (included)
