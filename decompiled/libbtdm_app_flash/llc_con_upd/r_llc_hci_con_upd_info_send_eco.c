/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> llc_con_upd.o -> r_llc_hci_con_upd_info_send_eco
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llc_hci_con_upd_info_send_eco(int param_1,int param_2,int param_3)

{
  undefined2 uVar1;
  undefined1 *puVar2;
  int iVar3;
  int iVar4;
  byte bVar5;
  undefined2 uStack_2c;
  undefined2 uStack_2a;
  undefined2 uStack_28;
  byte bStack_26;
  undefined1 uStack_25;
  undefined1 uStack_24;
  undefined1 uStack_23;
  undefined1 uStack_22;
  undefined1 uStack_21;
  
  r_lld_con_update_last_clock();
  if (((param_3 != 0) && (param_2 == 0)) &&
     ((*(ushort *)(*(int *)(&llc_env + param_1 * 4) + 0x42) & 1) == 0)) {
    iVar4 = r_sdk_config_get_opts_ext();
    *(ushort *)(param_3 + 0x12) = (ushort)*(byte *)(iVar4 + 0x10);
    iVar4 = r_sdk_config_get_opts_ext();
    *(ushort *)(param_3 + 0x10) = (ushort)*(byte *)(iVar4 + 0x10);
  }
  iVar4 = *(int *)(&llc_env + param_1 * 4);
  bVar5 = *(byte *)(param_3 + 0x2d) | *(byte *)(param_3 + 0x2e);
  if (param_2 == 0) {
    if ((*(short *)(iVar4 + 0xe) != *(short *)(param_3 + 0x28)) ||
       (*(int *)(param_3 + 0xc) != *(int *)(iVar4 + 0x10))) {
      *(short *)(iVar4 + 0xe) = *(short *)(param_3 + 0x28);
      bVar5 = 1;
      *(undefined2 *)(iVar4 + 0x10) = *(undefined2 *)(param_3 + 0xc);
      *(undefined2 *)(iVar4 + 0x12) = *(undefined2 *)(param_3 + 0xe);
    }
    r_llc_con_plan_set_update(param_1,param_3);
  }
  if (bVar5 != 0) {
    puVar2 = (undefined1 *)r_ke_msg_alloc(0x1104,param_1,0,10);
    *puVar2 = 3;
    puVar2[1] = (char)param_2;
    uVar1 = *(undefined2 *)(iVar4 + 0xe);
    *(short *)(puVar2 + 2) = (short)param_1;
    *(undefined2 *)(puVar2 + 4) = uVar1;
    *(undefined2 *)(puVar2 + 6) = *(undefined2 *)(iVar4 + 0x10);
    *(undefined2 *)(puVar2 + 8) = *(undefined2 *)(iVar4 + 0x12);
    r_hci_send_2_host();
  }
  if (*(char *)(param_3 + 0x2d) != '\0') {
    *(byte *)(iVar4 + 0x45) = *(byte *)(iVar4 + 0x45) & 0xef;
  }
  if (((bVar5 != 0) && (_bt_rf_coex_hooks_p != 0)) && (*(int *)(_bt_rf_coex_hooks_p + 4) != 0)) {
    iVar3 = r_llm_plan_elt_get(param_1);
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

