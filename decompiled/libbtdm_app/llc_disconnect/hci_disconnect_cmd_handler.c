/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> llc_disconnect.o -> hci_disconnect_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_disconnect_cmd_handler(uint param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  char cVar4;
  int iVar5;
  
  iVar5 = *(int *)(&llc_env + param_1 * 4);
  iVar1 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  if (((param_1 < *(byte *)(iVar1 + 0xd)) && (iVar1 = *(int *)(&llc_env + param_1 * 4), iVar1 != 0))
     && ((*(byte *)(iVar1 + 0x44) & 3) != 3)) {
    uVar3 = 0x3a;
    if ((*(byte *)(iVar5 + 0x45) & 1) == 0) {
      puVar2 = (undefined4 *)
               (**(code **)(_r_modules_funcs_p + 200))
                         (0x108,param_1 << 8 | 1,0xc,*(code **)(_r_modules_funcs_p + 200));
      *(undefined1 *)(puVar2 + 1) = 1;
      (**(code **)(_r_ip_funcs_p + 0x684))(param_1,0,*(code **)(_r_ip_funcs_p + 0x684));
      *puVar2 = *(undefined4 *)(_r_ip_funcs_p + 0x568);
      cVar4 = *(char *)(param_2 + 2);
      *(char *)(puVar2 + 2) = cVar4;
      if (cVar4 == '\x13') {
        cVar4 = '\x16';
      }
      *(char *)((int)puVar2 + 9) = cVar4;
      (**(code **)(_r_modules_funcs_p + 0xe0))(puVar2,*(code **)(_r_modules_funcs_p + 0xe0));
      uVar3 = 0;
      *(byte *)(iVar5 + 0x45) = *(byte *)(iVar5 + 0x45) | 1;
    }
  }
  else {
    uVar3 = 0;
    if ((_sdk_cfg_priv_opts & 0x40) == 0) {
      uVar3 = 0xc;
    }
  }
  (**(code **)(_r_ip_funcs_p + 0x634))(param_1,param_3,uVar3,*(code **)(_r_ip_funcs_p + 0x634));
  return 0;
}

