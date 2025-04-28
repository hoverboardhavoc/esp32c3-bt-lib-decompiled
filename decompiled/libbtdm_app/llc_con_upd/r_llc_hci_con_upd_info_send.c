/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> llc_con_upd.o -> r_llc_hci_con_upd_info_send
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llc_hci_con_upd_info_send(uint param_1,int param_2,int param_3)

{
  undefined2 uVar1;
  int iVar2;
  undefined1 *puVar3;
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
  
  iVar2 = *(int *)(&llc_env + param_1 * 4);
  bVar6 = *(byte *)(param_3 + 0x2d) | *(byte *)(param_3 + 0x2e);
  if (param_2 != 0) goto _L133;
  if (*(short *)(iVar2 + 0xe) == *(short *)(param_3 + 0x28)) {
    if (*(int *)(param_3 + 0xc) != *(int *)(iVar2 + 0x10)) goto _L134;
  }
  else {
_L134:
    *(short *)(iVar2 + 0xe) = *(short *)(param_3 + 0x28);
    bVar6 = 1;
    *(undefined2 *)(iVar2 + 0x10) = *(undefined2 *)(param_3 + 0xc);
    *(undefined2 *)(iVar2 + 0x12) = *(undefined2 *)(param_3 + 0xe);
  }
  (**(code **)(_r_ip_funcs_p + 0x5e4))(param_1,param_3,*(code **)(_r_ip_funcs_p + 0x5e4));
_L133:
  if (bVar6 != 0) {
    puVar3 = (undefined1 *)
             (**(code **)(_r_modules_funcs_p + 200))
                       (0x1104,param_1 & 0xffff,0,10,*(code **)(_r_modules_funcs_p + 200));
    *puVar3 = 3;
    puVar3[1] = (char)param_2;
    iVar4 = _r_ip_funcs_p;
    *(undefined2 *)(puVar3 + 4) = *(undefined2 *)(iVar2 + 0xe);
    uVar1 = *(undefined2 *)(iVar2 + 0x10);
    pcVar5 = *(code **)(iVar4 + 0x8c);
    *(short *)(puVar3 + 2) = (short)param_1;
    *(undefined2 *)(puVar3 + 6) = uVar1;
    *(undefined2 *)(puVar3 + 8) = *(undefined2 *)(iVar2 + 0x12);
    (*pcVar5)(pcVar5);
  }
  if (*(char *)(param_3 + 0x2d) != '\0') {
    *(byte *)(iVar2 + 0x45) = *(byte *)(iVar2 + 0x45) & 0xef;
  }
  if (((bVar6 != 0) && (_bt_rf_coex_hooks_p != 0)) && (*(int *)(_bt_rf_coex_hooks_p + 4) != 0)) {
    iVar4 = (**(code **)(_r_ip_funcs_p + 0x4f0))(param_1,*(code **)(_r_ip_funcs_p + 0x4f0));
    uStack_25 = 0;
    uStack_24 = 0;
    uStack_2c = (undefined2)*(undefined4 *)(iVar4 + 4);
    uStack_2a = *(undefined2 *)(iVar2 + 0x10);
    uStack_23 = 0;
    uStack_22 = 0;
    uStack_21 = 0;
    uStack_28 = (undefined2)*(undefined4 *)(iVar4 + 0x10);
    bStack_26 = (byte)*(undefined2 *)(iVar2 + 0x42) & 1;
    (**(code **)(_bt_rf_coex_hooks_p + 4))(param_1,7,&uStack_2c,*(code **)(_bt_rf_coex_hooks_p + 4))
    ;
  }
  return;
}

