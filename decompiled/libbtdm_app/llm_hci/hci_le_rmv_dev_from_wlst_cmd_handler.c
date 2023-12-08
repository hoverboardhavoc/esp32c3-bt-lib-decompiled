/*
 * Last changed at upstream commit bb9f0f59db474924c9288ab92aed1abb88bc9419
 * https://github.com/espressif/esp32c3-bt-lib/commit/bb9f0f59db474924c9288ab92aed1abb88bc9419
 * Upstream date: 2023-12-08 13:35:16 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(65db61f)
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
  char local_19;
  undefined1 auStack_18 [8];
  
  iVar3 = (**(code **)(_r_ip_funcs_p + 0x508))(*(code **)(_r_ip_funcs_p + 0x508));
  uVar5 = 0xc;
  if (iVar3 != 0) {
    if (0xfc < (byte)(*param_1 - 2U)) {
      local_19 = *param_1;
      memcpy(auStack_18,param_1 + 1,6);
      lld_wl_rpa_res(auStack_18,&local_19,0);
      uVar4 = (**(code **)(_r_ip_funcs_p + 0x4c8))
                        (auStack_18,local_19,*(code **)(_r_ip_funcs_p + 0x4c8));
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
                    (uVar4,auStack_18,local_19,*(code **)(_r_ip_funcs_p + 0x2c0));
          lld_wl_res_rem(uVar4);
          uVar5 = 0;
          goto _L211;
        }
      }
    }
    uVar5 = 0x12;
  }
_L211:
  (**(code **)(_r_ip_funcs_p + 0x4b8))(param_2,uVar5,*(code **)(_r_ip_funcs_p + 0x4b8));
  return 0;
}

