/*
 * Last changed at upstream commit aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * https://github.com/espressif/esp32c3-bt-lib/commit/aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * Upstream date: 2025-03-20 20:31:24 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(d74042a8)
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
    if (unaff_s1 == 0) goto _L85;
    if (uVar1 < *(ushort *)(unaff_s1 + 8)) goto _L82;
  }
  else {
    r_assert_err(0,"ke_task.c",0x1b2);
_L85:
    r_assert_param(uVar5,uVar1,"ke_task.c",0x1b9);
    piVar4 = (int *)(uint)_DAT_00000008;
    ebreak();
    param_1 = unaff_s3;
    param_2 = unaff_s4;
  }
  r_assert_param(uVar1,"ke_task.c",0x1ba,piVar4);
  if (*(ushort *)(unaff_s1 + 8) <= uVar1) {
    return;
  }
_L82:
  pbVar2 = (byte *)(uVar1 + *(int *)(unaff_s1 + 4));
  if (pbVar2 == (byte *)0x0) {
    r_assert_err(0,"ke_task.c",0x1c2);
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

