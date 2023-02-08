# toggle-x
アプリを実行するごとに事前に設定した2つのキーを交互にに入力する

## SrufacePenのショートカットに任意のトグルキーを設定する
1. toggle-x.cppの変数`key1`,`key2`の値を任意のキーコードのものに変更しVisualStudioでビルドし、利用する。実行速度の観点から、ハードコーディングしている。
2. ビルド済みの実行ファイルのショートカットを作成
3. SurfacePen設定のショートカットボタンから"プログラムを開く"で実行ファイルのショートカットを指定
4. うまく設定できていれば、SurfacePenのトップボタンを押すたびに`key1`と`key2`が交互に切り替わる