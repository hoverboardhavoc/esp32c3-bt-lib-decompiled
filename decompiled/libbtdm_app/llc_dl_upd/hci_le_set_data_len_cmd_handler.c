/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> llc_dl_upd.o -> hci_le_set_data_len_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_set_data_len_cmd_handler(uint param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  
  piVar2 = (int *)(&llc_env + param_1 * 4);
  iVar1 = *piVar2;
  iVar3 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  uVar5 = 0xc;
  if (param_1 < *(byte *)(iVar3 + 0xd)) {
    uVar5 = 0xc;
    if (((*piVar2 != 0) && ((*(byte *)(*piVar2 + 0x44) & 3) != 3)) &&
       (uVar5 = 0x3a, (*(byte *)(iVar1 + 0x45) & 0x20) == 0)) {
      iVar3 = (**(code **)(_r_plf_funcs_p + 0x38))(0x3a,*(code **)(_r_plf_funcs_p + 0x38));
      uVar5 = 0x1a;
      if (((param_1 < *(byte *)(iVar3 + 0xd)) && (*piVar2 != 0)) &&
         (((int)(uint)*(byte *)(*piVar2 + 0x30) >> 5 & 1U) != 0)) {
        uVar5 = 0x12;
        if ((ushort)(*(short *)(param_2 + 2) - 0x1bU) < 0xe1) {
          if ((ushort)(*(short *)(param_2 + 4) - 0x148U) < 0x4149) {
            if ((*(short *)(iVar1 + 0x14) != *(short *)(param_2 + 2)) ||
               (*(short *)(iVar1 + 0x18) != *(short *)(param_2 + 4))) {
              puVar4 = (undefined4 *)
                       (**(code **)(_r_modules_funcs_p + 200))
                                 (0x10a,param_1 << 8 | 1,0x14,*(code **)(_r_modules_funcs_p + 200));
              *(undefined1 *)(puVar4 + 1) = 7;
              (**(code **)(_r_ip_funcs_p + 0x684))(param_1,0,*(code **)(_r_ip_funcs_p + 0x684));
              *puVar4 = *(undefined4 *)(_r_ip_funcs_p + 0x5cc);
              *(undefined2 *)(puVar4 + 2) = *(undefined2 *)(param_2 + 2);
              *(undefined2 *)((int)puVar4 + 10) = *(undefined2 *)(param_2 + 4);
              puVar4[3] = 0x429000fb;
              *(undefined1 *)(puVar4 + 4) = 1;
              (**(code **)(_r_modules_funcs_p + 0xe0))(puVar4,*(code **)(_r_modules_funcs_p + 0xe0))
              ;
              *(byte *)(iVar1 + 0x45) = *(byte *)(iVar1 + 0x45) | 0x20;
            }
            uVar5 = 0;
            *(undefined2 *)(iVar1 + 0x20) = *(undefined2 *)(param_2 + 2);
            *(undefined2 *)(iVar1 + 0x22) = *(undefined2 *)(param_2 + 4);
          }
        }
      }
    }
  }
  (**(code **)(_r_ip_funcs_p + 0x630))(param_1,param_3,uVar5,*(code **)(_r_ip_funcs_p + 0x630));
  return 0;
}

