Лабораторная работа: Создание пайплайна сборки и выгрузки артефактов с использованием GitHub Actions и Docker

Цель работы: Ознакомиться с принципами непрерывной интеграции и непрерывной доставки (CI/CD), научиться создавать пайплайн сборки и выгрузки готовых артефактов с использованием GitHub Actions и технологии Docker.

Задачи:

1. Создать приложение по вашему выбору (веб-приложение, мобильное приложение, консольное приложение и т.д.).
2. Настроить систему сборки и установить необходимые зависимости.
3. Создать простой пайплайн сборки в GitHub Actions.
4. Расширить пайплайн для упаковки приложения в Docker-контейнер.
5. Добавить шаги для выгрузки готового Docker-контейнера после успешной сборки в пайплайн и загрузки контейнера в Docker Hub.
6. Добавить дополнительные шаги в пайплайн, например, статический анализ кода, проверка стиля кодирования и другие полезные инструменты.
7. Добавить шаги для развертывания приложения на тестовом сервере или сборка на собственном подключенном агенте (можно использовать облачные сервисы или собственный ПК), если возможно.

Подзадачи:

Выполнены:
+ Создано приложение консольное С++ приложение.
+ Настроена система сборки и установлены необходимые зависимости.
+ Создан простой пайплайн сборки в GitHub Actions.
+ Добавлена выгрузка готового артефакта после успешной сборки в пайплайн.
+ Пайплайн в GitHub Actions настроен для выгрузки артефакта в Telegram.
+ Добавлена упаковка готового приложения в Docker-контейнер.
+ Добавлена выгрузка готового Docker-контейнера после успешной сборки контейнера в Docker Hub (alenanish.linked_list)
+  Добавлены дополнительные шаги в пайплайн: статический анализ кода (cppcheck), проверка стиля кодирования (cpplint).
+  Пайплайн в GitHub Actions настроен для автоматической сборки, тестирования и выгрузки Docker-контейнера при каждом пуше в репозиторий или создании Pull Request.

В процессе:
  
- Добавлены шаги для развертывания приложения на тестовом сервере или сборка проходит на собственном подключенном агенте (можно использовать облачные сервисы или собственный ПК).

