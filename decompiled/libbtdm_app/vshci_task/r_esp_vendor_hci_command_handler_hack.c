/*
 * Last changed at upstream commit b223604efd557d0a5314afb3b751229df424d244
 * https://github.com/espressif/esp32c3-bt-lib/commit/b223604efd557d0a5314afb3b751229df424d244
 * Upstream date: 2021-06-24 21:26:02 +0800
 * Upstream subject: Update ESP32-C3 and ESP32-S3 bt lib (9c99115)
 * Source: libbtdm_app -> vshci_task.o -> r_esp_vendor_hci_command_handler_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 r_esp_vendor_hci_command_handler_hack(undefined4 param_1,undefined4 param_2,uint param_3)

{
  undefined4 uVar1;
  uint uVar2;
  ushort *puVar3;
  
  if ((param_3 != 0xfd08) && (param_3 < 0xfd0b)) {
    uVar1 = r_esp_vendor_hci_command_handler();
    return uVar1;
  }
  if ((esp_handler_ext != (undefined *)0x0) && (DAT_00010120 != 0)) {
    uVar2 = 0;
    puVar3 = (ushort *)esp_handler_ext;
    do {
      if (*puVar3 == param_3) {
        if (*(code **)(puVar3 + 2) == (code *)0x0) {
          return 0;
        }
                    /* WARNING: Could not recover jumptable at 0x000100ee. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        uVar1 = (**(code **)(puVar3 + 2))(param_3,param_1,param_2,param_3);
        return uVar1;
      }
      uVar2 = uVar2 + 1;
      puVar3 = puVar3 + 4;
    } while (uVar2 < DAT_00010120);
  }
  return 0;
}

