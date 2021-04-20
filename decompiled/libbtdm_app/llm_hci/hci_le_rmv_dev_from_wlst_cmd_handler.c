/*
 * Last changed at upstream commit 352d001fc7f5d34243047454b3f9e684577ce3e0
 * https://github.com/espressif/esp32c3-bt-lib/commit/352d001fc7f5d34243047454b3f9e684577ce3e0
 * Upstream date: 2021-04-20 15:58:00 +0800
 * Upstream subject: ESP32C3, ESP32S3: update libbtdm_app.a(47235b66)
 * Source: libbtdm_app -> llm_hci.o -> hci_le_rmv_dev_from_wlst_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_rmv_dev_from_wlst_cmd_handler(char *param_1,undefined4 param_2)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  
  iVar3 = (**(code **)(_r_ip_funcs_p + 0x508))(*(code **)(_r_ip_funcs_p + 0x508));
  uVar5 = 0xc;
  if (iVar3 != 0) {
    if (0xfc < (byte)(*param_1 - 2U)) {
      uVar4 = (**(code **)(_r_ip_funcs_p + 0x4c8))(param_1 + 1,*(code **)(_r_ip_funcs_p + 0x4c8));
      if (uVar4 < 0xc) {
        iVar3 = _p_llm_env + uVar4 * 10;
        bVar1 = *(byte *)(iVar3 + 0x2d);
        if ((bVar1 & 2) != 0) {
          if ((bVar1 & 4) == 0) {
            bVar2 = 0xfc;
          }
          else {
            bVar2 = 0xfd;
          }
          *(byte *)(iVar3 + 0x2d) = bVar1 & bVar2;
          (**(code **)(_r_ip_funcs_p + 0x2c0))
                    (param_1 + 1,*param_1,*(code **)(_r_ip_funcs_p + 0x2c0));
          uVar5 = 0;
          goto _L36;
        }
      }
    }
    uVar5 = 0x12;
  }
_L36:
  (**(code **)(_r_ip_funcs_p + 0x4b8))(param_2,uVar5,*(code **)(_r_ip_funcs_p + 0x4b8));
  return 0;
}

