/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> llc_encrypt.o -> hci_le_start_enc_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_start_enc_cmd_handler(uint param_1,int param_2,undefined4 param_3)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  
  iVar3 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
  if (*(char *)(iVar3 + 0x20) == '\0') {
    (**(code **)(_r_ip_funcs_p + 0x634))(param_1,param_3,0xc,*(code **)(_r_ip_funcs_p + 0x634));
    return 0;
  }
  piVar1 = (int *)(&llc_env + param_1 * 4);
  iVar5 = *piVar1;
  iVar3 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  uVar4 = 0xc;
  if (param_1 < *(byte *)(iVar3 + 0xd)) {
    uVar4 = 0xc;
    if (((*piVar1 != 0) && ((*(byte *)(*piVar1 + 0x44) & 3) != 3)) &&
       ((*(ushort *)(iVar5 + 0x42) & 1) != 0)) {
      iVar3 = (**(code **)(_r_plf_funcs_p + 0x38))(0xc,*(code **)(_r_plf_funcs_p + 0x38));
      uVar4 = 0x1a;
      if (((param_1 < *(byte *)(iVar3 + 0xd)) && (*piVar1 != 0)) &&
         (((*(byte *)(*piVar1 + 0x30) & 1) != 0 &&
          (uVar4 = 0x3a, (*(byte *)(iVar5 + 0x45) & 8) == 0)))) {
        puVar2 = (undefined4 *)
                 (**(code **)(_r_modules_funcs_p + 200))
                           (0x109,param_1 << 8 | 1,0x3c,*(code **)(_r_modules_funcs_p + 200));
        iVar3 = _r_ip_funcs_p;
        *(undefined1 *)(puVar2 + 1) = 3;
        (**(code **)(iVar3 + 0x684))(param_1,0,*(code **)(iVar3 + 0x684));
        *puVar2 = *(undefined4 *)(_r_ip_funcs_p + 0x598);
        memcpy(puVar2 + 2,(void *)(param_2 + 2),8);
        *(undefined2 *)(puVar2 + 0xe) = *(undefined2 *)(param_2 + 10);
        memcpy(puVar2 + 4,(void *)(param_2 + 0xc),0x10);
        *(byte *)((int)puVar2 + 0x3a) = (byte)((int)(uint)*(ushort *)(iVar5 + 0x42) >> 5) & 1;
        (**(code **)(_r_modules_funcs_p + 0xe0))(puVar2,*(code **)(_r_modules_funcs_p + 0xe0));
        uVar4 = 0;
        *(byte *)(iVar5 + 0x45) = *(byte *)(iVar5 + 0x45) | 8;
      }
    }
  }
  (**(code **)(_r_ip_funcs_p + 0x634))(param_1,param_3,uVar4,*(code **)(_r_ip_funcs_p + 0x634));
  return 0;
}

