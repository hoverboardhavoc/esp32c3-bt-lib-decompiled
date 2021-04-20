/*
 * Last changed at upstream commit 352d001fc7f5d34243047454b3f9e684577ce3e0
 * https://github.com/espressif/esp32c3-bt-lib/commit/352d001fc7f5d34243047454b3f9e684577ce3e0
 * Upstream date: 2021-04-20 15:58:00 +0800
 * Upstream subject: ESP32C3, ESP32S3: update libbtdm_app.a(47235b66)
 * Source: libbtdm_app -> llm_hci.o -> hci_le_set_addr_resol_en_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_set_addr_resol_en_cmd_handler(byte *param_1,undefined4 param_2)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar3 = (**(code **)(_r_ip_funcs_p + 0x504))(*(code **)(_r_ip_funcs_p + 0x504));
  iVar2 = _p_llm_env;
  uVar4 = 0xc;
  if (iVar3 == 0) {
    bVar1 = *param_1;
    uVar4 = 0x12;
    if (bVar1 < 2) {
      *(byte *)(_p_llm_env + 0xc6) = bVar1 & 1;
      if (bVar1 == 0) {
        (**(code **)(_r_modules_funcs_p + 0xb8))(6,0,*(code **)(_r_modules_funcs_p + 0xb8));
      }
      else {
        (**(code **)(_r_modules_funcs_p + 0xc4))
                  (6,0,(uint)*(ushort *)(iVar2 + 0xc4) * 100,*(code **)(_r_modules_funcs_p + 0xc4));
        (**(code **)(_r_ip_funcs_p + 0x294))(*(code **)(_r_ip_funcs_p + 0x294));
      }
      uVar4 = 0;
    }
  }
  (**(code **)(_r_ip_funcs_p + 0x4b8))(param_2,uVar4,*(code **)(_r_ip_funcs_p + 0x4b8));
  return 0;
}

