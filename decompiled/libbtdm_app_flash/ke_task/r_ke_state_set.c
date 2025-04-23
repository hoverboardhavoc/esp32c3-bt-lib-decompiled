/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> ke_task.o -> r_ke_state_set
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_ke_state_set(uint param_1,uint param_2)

{
  int iVar1;
  byte *pbVar2;
  int iVar3;
  undefined2 uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar6 = param_1 & 0xff;
  uVar5 = param_1 >> 8;
  uVar4 = 0x1e;
  if (0x1e < uVar6) goto _L82;
  iVar1 = *(int *)(&ke_task_env + uVar6 * 4);
  if (iVar1 == 0) {
    do {
      r_assert_param(uVar6,uVar5,"ke_task.c",0x1bc);
      ebreak();
      uVar4 = _DAT_00000008;
_L82:
      r_assert_err(0,"ke_task.c",0x1b5,uVar4);
    } while( true );
  }
  if (*(ushort *)(iVar1 + 8) <= uVar5) {
    r_assert_param(uVar5,"ke_task.c",0x1bd);
  }
  iVar3 = r_sdk_config_get_opts_ext();
  if (((*(uint *)(iVar3 + 0x28) & 2) != 0) &&
     (iVar3 = r_sdk_config_get_opts_ext(), *(byte *)(iVar3 + 0x2c) < 3)) {
    r_ble_log_internal_x1(0x4065000e,param_2 << 0x10 | param_1);
  }
  if (uVar5 < *(ushort *)(iVar1 + 8)) {
    pbVar2 = (byte *)(*(int *)(iVar1 + 4) + uVar5);
    if (pbVar2 == (byte *)0x0) {
      r_assert_err(0,"ke_task.c",0x1c6);
    }
    if (*pbVar2 != param_2) {
      *pbVar2 = (byte)param_2;
      while (iVar1 = r_ke_queue_extract(&ke_env,0x10000,param_1), iVar1 != 0) {
        (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
        r_co_list_push_back(&ke_env,iVar1);
        (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
        iVar3 = r_sdk_config_get_opts_ext();
        if (((*(uint *)(iVar3 + 0x28) & 2) != 0) &&
           (iVar3 = r_sdk_config_get_opts_ext(), *(byte *)(iVar3 + 0x2c) < 3)) {
          r_ble_log_internal_x1(0x4045000c,iVar1);
        }
        r_ke_event_set(3);
      }
      return;
    }
  }
  return;
}

