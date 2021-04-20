/*
 * Last changed at upstream commit 352d001fc7f5d34243047454b3f9e684577ce3e0
 * https://github.com/espressif/esp32c3-bt-lib/commit/352d001fc7f5d34243047454b3f9e684577ce3e0
 * Upstream date: 2021-04-20 15:58:00 +0800
 * Upstream subject: ESP32C3, ESP32S3: update libbtdm_app.a(47235b66)
 * Source: libbtdm_app -> llm_hci.o -> hci_le_clear_wlst_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_clear_wlst_cmd_handler(undefined4 param_1)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  
  iVar4 = (**(code **)(_r_ip_funcs_p + 0x508))(*(code **)(_r_ip_funcs_p + 0x508));
  uVar5 = 0xc;
  if (iVar4 != 0) {
    uVar3 = 0;
    do {
      iVar4 = _p_llm_env;
      iVar6 = uVar3 * 10 + _p_llm_env;
      bVar1 = *(byte *)(iVar6 + 0x2d);
      if ((bVar1 & 1) != 0) {
        if ((bVar1 & 4) == 0) {
          bVar2 = 0xfc;
        }
        else {
          bVar2 = 0xfd;
        }
        *(byte *)(iVar6 + 0x2d) = bVar1 & bVar2;
        (**(code **)(_r_ip_funcs_p + 0x2c0))
                  (uVar3 & 0xff,iVar4 + uVar3 * 10 + 0x24,*(undefined1 *)(iVar4 + uVar3 * 10 + 0x2c)
                   ,*(code **)(_r_ip_funcs_p + 0x2c0));
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 != 0xc);
    uVar5 = 0;
  }
  (**(code **)(_r_ip_funcs_p + 0x4b8))(param_1,uVar5,*(code **)(_r_ip_funcs_p + 0x4b8));
  return 0;
}

