/*
 * Last changed at upstream commit 352d001fc7f5d34243047454b3f9e684577ce3e0
 * https://github.com/espressif/esp32c3-bt-lib/commit/352d001fc7f5d34243047454b3f9e684577ce3e0
 * Upstream date: 2021-04-20 15:58:00 +0800
 * Upstream subject: ESP32C3, ESP32S3: update libbtdm_app.a(47235b66)
 * Source: libbtdm_app -> vshci_task.o -> r_esp_vendor_hci_command_handler_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4
r_esp_vendor_hci_command_handler_hack
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  undefined4 uVar1;
  uint uVar2;
  ushort *puVar3;
  
  if ((param_4 != 0xfd08) && (param_4 < 0xfd0b)) {
    uVar1 = r_esp_vendor_hci_command_handler();
    return uVar1;
  }
  if ((esp_handler_ext != (undefined *)0x0) && (DAT_00010124 != 0)) {
    uVar2 = 0;
    puVar3 = (ushort *)esp_handler_ext;
    while (*puVar3 != param_4) {
      uVar2 = uVar2 + 1;
      puVar3 = puVar3 + 4;
      if (DAT_00010124 <= uVar2) {
        return param_1;
      }
    }
    if (*(code **)(puVar3 + 2) != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x000100ee. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar1 = (**(code **)(puVar3 + 2))(param_4,param_2,param_3,param_4);
      return uVar1;
    }
    return param_1;
  }
  return 0;
}

