/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> llc_con_upd.o -> r_llc_hci_con_upd_info_send_eco
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llc_hci_con_upd_info_send_eco(uint param_1,int param_2,int param_3)

{
  undefined2 uVar1;
  undefined1 *puVar2;
  int iVar3;
  int iVar4;
  code *pcVar5;
  byte bVar6;
  undefined2 uStack_2c;
  undefined2 uStack_2a;
  undefined2 uStack_28;
  byte bStack_26;
  undefined1 uStack_25;
  undefined1 uStack_24;
  undefined1 uStack_23;
  undefined1 uStack_22;
  undefined1 uStack_21;
  
  (**(code **)(_r_ip_funcs_p + 2000))(*(code **)(_r_ip_funcs_p + 2000));
  if (((param_3 != 0) && (param_2 == 0)) &&
     ((*(ushort *)(*(int *)(&llc_env + param_1 * 4) + 0x42) & 1) == 0)) {
    iVar4 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
    *(ushort *)(param_3 + 0x12) = (ushort)*(byte *)(iVar4 + 0x10);
    iVar4 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
    *(ushort *)(param_3 + 0x10) = (ushort)*(byte *)(iVar4 + 0x10);
  }
  iVar4 = *(int *)(&llc_env + param_1 * 4);
  bVar6 = *(byte *)(param_3 + 0x2d) | *(byte *)(param_3 + 0x2e);
  if (param_2 == 0) {
    if ((*(short *)(iVar4 + 0xe) != *(short *)(param_3 + 0x28)) ||
       (*(int *)(param_3 + 0xc) != *(int *)(iVar4 + 0x10))) {
      *(short *)(iVar4 + 0xe) = *(short *)(param_3 + 0x28);
      bVar6 = 1;
      *(undefined2 *)(iVar4 + 0x10) = *(undefined2 *)(param_3 + 0xc);
      *(undefined2 *)(iVar4 + 0x12) = *(undefined2 *)(param_3 + 0xe);
    }
    (**(code **)(_r_ip_funcs_p + 0x5e4))(param_1,param_3,*(code **)(_r_ip_funcs_p + 0x5e4));
  }
  if (bVar6 != 0) {
    puVar2 = (undefined1 *)
             (**(code **)(_r_modules_funcs_p + 200))
                       (0x1104,param_1 & 0xffff,0,10,*(code **)(_r_modules_funcs_p + 200));
    *puVar2 = 3;
    puVar2[1] = (char)param_2;
    iVar3 = _r_ip_funcs_p;
    *(undefined2 *)(puVar2 + 4) = *(undefined2 *)(iVar4 + 0xe);
    uVar1 = *(undefined2 *)(iVar4 + 0x10);
    pcVar5 = *(code **)(iVar3 + 0x8c);
    *(short *)(puVar2 + 2) = (short)param_1;
    *(undefined2 *)(puVar2 + 6) = uVar1;
    *(undefined2 *)(puVar2 + 8) = *(undefined2 *)(iVar4 + 0x12);
    (*pcVar5)(pcVar5);
  }
  if (*(char *)(param_3 + 0x2d) != '\0') {
    *(byte *)(iVar4 + 0x45) = *(byte *)(iVar4 + 0x45) & 0xef;
  }
  if (((bVar6 != 0) && (_bt_rf_coex_hooks_p != 0)) && (*(int *)(_bt_rf_coex_hooks_p + 4) != 0)) {
    iVar3 = (**(code **)(_r_ip_funcs_p + 0x4f0))(param_1,*(code **)(_r_ip_funcs_p + 0x4f0));
    uStack_25 = 0;
    uStack_24 = 0;
    uStack_2c = (undefined2)*(undefined4 *)(iVar3 + 4);
    uStack_2a = *(undefined2 *)(iVar4 + 0x10);
    uStack_23 = 0;
    uStack_22 = 0;
    uStack_21 = 0;
    uStack_28 = (undefined2)*(undefined4 *)(iVar3 + 0x10);
    bStack_26 = (byte)*(undefined2 *)(iVar4 + 0x42) & 1;
    (**(code **)(_bt_rf_coex_hooks_p + 4))(param_1,7,&uStack_2c,*(code **)(_bt_rf_coex_hooks_p + 4))
    ;
  }
  return;
}

