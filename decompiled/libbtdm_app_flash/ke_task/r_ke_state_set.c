/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
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
  uint uVar1;
  byte *pbVar2;
  int iVar3;
  uint extraout_a1;
  int iVar4;
  uint uVar5;
  
  uVar5 = param_1 & 0xff;
  uVar1 = param_1 >> 8;
  if (uVar5 < 0x1f) goto _L83;
  r_assert_err(0,"ke_task.c",0x1b5);
  do {
    param_1 = r_assert_param(uVar5,uVar1,"ke_task.c",0x1bc);
    ebreak();
    param_2 = extraout_a1;
_L83:
    iVar4 = *(int *)(&ke_task_env + uVar5 * 4);
  } while (iVar4 == 0);
  if (*(ushort *)(iVar4 + 8) <= uVar1) {
    r_assert_param(uVar1,"ke_task.c",0x1bd);
  }
  iVar3 = r_sdk_config_get_opts_ext();
  if (((*(uint *)(iVar3 + 0x28) & 2) != 0) &&
     (iVar3 = r_sdk_config_get_opts_ext(), *(byte *)(iVar3 + 0x2c) < 3)) {
    r_ble_log_internal_x1(0x4065000e,param_2 << 0x10 | param_1);
  }
  if (uVar1 < *(ushort *)(iVar4 + 8)) {
    pbVar2 = (byte *)(uVar1 + *(int *)(iVar4 + 4));
    if (pbVar2 == (byte *)0x0) {
      r_assert_err(0,"ke_task.c",0x1c6);
    }
    if (*pbVar2 != param_2) {
      *pbVar2 = (byte)param_2;
      while (iVar4 = r_ke_queue_extract(&ke_env,0x10000,param_1), iVar4 != 0) {
        (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
        r_co_list_push_back(&ke_env,iVar4);
        (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
        iVar3 = r_sdk_config_get_opts_ext();
        if (((*(uint *)(iVar3 + 0x28) & 2) != 0) &&
           (iVar3 = r_sdk_config_get_opts_ext(), *(byte *)(iVar3 + 0x2c) < 3)) {
          r_ble_log_internal_x1(0x4045000c,iVar4);
        }
        r_ke_event_set(3);
      }
      return;
    }
  }
  return;
}

