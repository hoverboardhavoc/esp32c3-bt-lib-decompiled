/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
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
  uint extraout_a1;
  int iVar3;
  uint uVar4;
  
  uVar4 = param_1 & 0xff;
  uVar1 = param_1 >> 8;
  if (uVar4 < 0x1f) goto _L78;
  r_assert_err(0,"ke_task.c",0x1b5);
  do {
    param_1 = r_assert_param(uVar4,uVar1,"ke_task.c",0x1bc);
    ebreak();
    param_2 = extraout_a1;
_L78:
    iVar3 = *(int *)(&ke_task_env + uVar4 * 4);
  } while (iVar3 == 0);
  if (*(ushort *)(iVar3 + 8) <= uVar1) {
    r_assert_param(uVar1,"ke_task.c",0x1bd);
  }
  r_ble_log_internal_x1(0x406a023b,param_2 << 0x10 | param_1);
  if (uVar1 < *(ushort *)(iVar3 + 8)) {
    pbVar2 = (byte *)(uVar1 + *(int *)(iVar3 + 4));
    if (pbVar2 == (byte *)0x0) {
      r_assert_err(0,"ke_task.c",0x1c6);
    }
    if (*pbVar2 != param_2) {
      *pbVar2 = (byte)param_2;
      while (iVar3 = r_ke_queue_extract(&ke_env,0x10000,param_1), iVar3 != 0) {
        (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
        r_co_list_push_back(&ke_env,iVar3);
        (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
        r_ble_log_internal_x1(0x404a023a,iVar3);
        r_ke_event_set(3);
      }
      return;
    }
  }
  return;
}

