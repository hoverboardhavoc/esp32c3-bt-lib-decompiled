/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
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
  int unaff_s1;
  int iVar3;
  int *piVar4;
  uint uVar5;
  uint unaff_s3;
  uint unaff_s4;
  
  uVar5 = param_1 & 0xff;
  uVar1 = param_1 >> 8;
  if (uVar5 < 0x1f) {
    piVar4 = (int *)(&ke_task_env + uVar5 * 4);
    unaff_s1 = *piVar4;
    if (unaff_s1 == 0) goto _L83;
    if (uVar1 < *(ushort *)(unaff_s1 + 8)) goto _L80;
  }
  else {
    r_assert_err(0,"ke_task.c",0x1ae);
_L83:
    r_assert_param(uVar5,uVar1,"ke_task.c",0x1b5);
    piVar4 = (int *)(uint)_DAT_00000008;
    ebreak();
    param_1 = unaff_s3;
    param_2 = unaff_s4;
  }
  r_assert_param(uVar1,"ke_task.c",0x1b6,piVar4);
  if (*(ushort *)(unaff_s1 + 8) <= uVar1) {
    return;
  }
_L80:
  pbVar2 = (byte *)(uVar1 + *(int *)(unaff_s1 + 4));
  if (pbVar2 == (byte *)0x0) {
    r_assert_err(0,"ke_task.c",0x1be);
  }
  if (*pbVar2 == param_2) {
    return;
  }
  *pbVar2 = (byte)param_2;
  while (iVar3 = r_ke_queue_extract(&ke_env,0x10000,param_1), iVar3 != 0) {
    (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
    r_co_list_push_back(&ke_env,iVar3);
    (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
    r_ke_event_set(3);
  }
  return;
}

