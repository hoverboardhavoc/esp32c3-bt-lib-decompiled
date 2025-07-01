/*
 * Last changed at upstream commit 0c68809d62e432427de97b5294f6619307f62f40
 * https://github.com/espressif/esp32c3-bt-lib/commit/0c68809d62e432427de97b5294f6619307f62f40
 * Upstream date: 2025-07-01 15:07:54 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2edb0b0)
 * Source: libbtdm_app_flash -> sch_prog.o -> r_sch_prog_push
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_sch_prog_push(undefined4 *param_1)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  
  uVar2 = (uint)DAT_00011101;
  iVar7 = (uVar2 - 1 & 0xf) * 0x10;
  uVar8 = uVar2 - DAT_00011100 & 0xf;
  if (param_1[1] == *(int *)(&sch_prog_env + iVar7)) {
    r_assert_err(0,"sch_prog.c",0x2a3);
  }
  iVar3 = r_emi_get_mem_addr_by_offset(0);
  iVar6 = uVar2 * 0x10;
  if (((*(ushort *)(iVar3 + iVar6) >> 3 & 7) == 1) ||
     (iVar3 = r_emi_get_mem_addr_by_offset(0), (*(ushort *)(iVar3 + iVar6) >> 3 & 7) == 2)) {
    r_assert_param(DAT_00011100,uVar2,"sch_prog.c",0x2a6);
  }
  if (0xd < uVar8) {
    iVar3 = r_emi_get_mem_addr_by_offset(0);
    uVar1 = *(ushort *)((uVar2 - 2 & 0xf) * 0x10 + iVar3);
    iVar3 = r_emi_get_mem_addr_by_offset(0);
    r_assert_warn((int)(uint)uVar1 >> 3 & 7,*(ushort *)(iVar7 + iVar3) >> 3 & 7,"sch_prog.c",0x2ab);
  }
  uVar5 = param_1[1];
  *(undefined4 *)(r_assert_err + iVar6) = param_1[4];
  uVar4 = *param_1;
  *(undefined4 *)(&sch_prog_env + iVar6) = uVar5;
  *(undefined4 *)(r_emi_get_mem_addr_by_offset + iVar6) = uVar4;
  r_assert_param[iVar6] = (code)0x1;
  iVar7 = r_emi_get_mem_addr_by_offset(0);
  *(short *)(iVar6 + 2 + iVar7) = (short)uVar5;
  uVar1 = *(ushort *)((int)param_1 + 6);
  iVar7 = r_emi_get_mem_addr_by_offset(0);
  uVar2 = param_1[2];
  *(ushort *)(iVar6 + 4 + iVar7) = (ushort)(((uint)uVar1 << 0x14) >> 0x14);
  if (0x270 < uVar2) {
    r_assert_err(0,"sch_prog.c",0x2b6);
  }
  iVar7 = param_1[2];
  if ((0x270U - iVar7 & 0xfc00) != 0) {
    r_assert_err(0,"sch_prog.c",0x1f7);
  }
  iVar3 = r_emi_get_mem_addr_by_offset(0);
  *(short *)(iVar6 + 6 + iVar3) = (short)((0x270U - iVar7) * 0x10000 >> 0x10);
  uVar2 = param_1[3];
  if (uVar2 < 0x8000) {
    iVar7 = r_emi_get_mem_addr_by_offset(0);
    uVar1 = (ushort)(uVar2 + 1 >> 1);
  }
  else {
    uVar2 = (uVar2 + 0x271) / 0x271;
    if ((uVar2 >> 0xf & 1) != 0) {
      r_assert_err(0,"sch_prog.c",0x249);
    }
    iVar7 = r_emi_get_mem_addr_by_offset(0);
    uVar1 = (ushort)uVar2 | 0x8000;
  }
  *(ushort *)(iVar7 + iVar6 + 10) = uVar1;
  uVar2 = (uint)*(byte *)((int)param_1 + 0x16);
  if (0x1f < uVar2) {
    uVar2 = 0x1f;
  }
  uVar1 = (ushort)*(byte *)((int)param_1 + 0x15);
  if (0x1f < *(byte *)((int)param_1 + 0x15)) {
    uVar1 = 0x1f;
  }
  iVar7 = r_emi_get_mem_addr_by_offset(0);
  *(ushort *)(iVar6 + 0xc + iVar7) = (ushort)(uVar2 << 8) | uVar1;
  r_sch_prog_ble_push_hack(param_1,0xd < uVar8);
  DAT_00011101 = DAT_00011101 + 1 & 0xf;
  DAT_00011102 = DAT_00011102 + '\x01';
  r_rwip_prevent_sleep_set_hack(0x200);
  return;
}

