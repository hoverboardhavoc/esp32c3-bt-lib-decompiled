/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> llc_disconnect.o -> hci_disconnect_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_disconnect_cmd_handler(uint param_1,int param_2,undefined4 param_3)

{
  byte bVar1;
  int iVar2;
  undefined4 *puVar3;
  char cVar4;
  int iVar5;
  
  iVar5 = *(int *)(&llc_env + param_1 * 4);
  iVar2 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  if (((param_1 < *(byte *)(iVar2 + 0xd)) && (iVar2 = *(int *)(&llc_env + param_1 * 4), iVar2 != 0))
     && ((*(byte *)(iVar2 + 0x44) & 3) != 3)) {
    bVar1 = *(byte *)(iVar5 + 0x45) & 1;
    if ((*(byte *)(iVar5 + 0x45) & 1) == 0) {
      puVar3 = (undefined4 *)
               (**(code **)(_r_modules_funcs_p + 200))
                         (0x108,param_1 << 8 | 1,0xc,*(code **)(_r_modules_funcs_p + 200));
      *(undefined1 *)(puVar3 + 1) = 1;
      (**(code **)(_r_ip_funcs_p + 0x684))(param_1,0,*(code **)(_r_ip_funcs_p + 0x684));
      *puVar3 = *(undefined4 *)(_r_ip_funcs_p + 0x568);
      cVar4 = *(char *)(param_2 + 2);
      *(char *)(puVar3 + 2) = cVar4;
      if (cVar4 == '\x13') {
        cVar4 = '\x16';
      }
      *(char *)((int)puVar3 + 9) = cVar4;
      (**(code **)(_r_modules_funcs_p + 0xe0))(puVar3,*(code **)(_r_modules_funcs_p + 0xe0));
      *(byte *)(iVar5 + 0x45) = *(byte *)(iVar5 + 0x45) | 1;
    }
    else {
      bVar1 = 0x3a;
    }
  }
  else {
    bVar1 = 0;
    if ((_sdk_cfg_priv_opts & 0x40) == 0) {
      bVar1 = 0xc;
    }
  }
  (**(code **)(_r_ip_funcs_p + 0x634))(param_1,param_3,bVar1,*(code **)(_r_ip_funcs_p + 0x634));
  return 0;
}

