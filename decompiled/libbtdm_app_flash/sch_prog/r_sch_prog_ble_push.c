/*
 * Last changed at upstream commit aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * https://github.com/espressif/esp32c3-bt-lib/commit/aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * Upstream date: 2025-03-20 20:31:24 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(d74042a8)
 * Source: libbtdm_app_flash -> sch_prog.o -> r_sch_prog_ble_push
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_sch_prog_ble_push(int param_1,int param_2)

{
  byte bVar1;
  char cVar2;
  byte bVar3;
  byte bVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int extraout_a1;
  uint uVar8;
  int iVar9;
  uint uVar10;
  ushort uVar11;
  uint uVar12;
  uint uVar13;
  
  bVar4 = sch_prog_env;
  if (*(char *)(param_1 + 0x19) != '\0') {
    return;
  }
  uVar11 = (ushort)*(byte *)(param_1 + 0x1c);
  uVar10 = (uint)sch_prog_env;
  if (uVar11 != 0) {
    uVar11 = (ushort)*(byte *)(param_1 + 0x1d);
  }
  uVar8 = (uint)*(byte *)(param_1 + 0x17) << 8;
  if ((uVar8 & 0xe000) != 0) {
    r_assert_err(0,"sch_prog.c",0x323);
  }
  if ((uVar11 & 0xfffc) != 0) {
    r_assert_err(0,"sch_prog.c",0x324);
  }
  iVar6 = r_emi_get_mem_addr_by_offset(0);
  iVar9 = uVar10 * 0x10;
  *(ushort *)(iVar6 + iVar9 + 0xe) = (ushort)uVar8 | uVar11;
  bVar1 = *(byte *)(param_1 + 0x18);
  iVar6 = r_emi_get_mem_addr_by_offset(0);
  cVar2 = *(char *)(param_1 + 0x1c);
  *(short *)(iVar6 + iVar9 + 8) = (short)((uint)bVar1 * 0x5a + 0x400 >> 1);
  uVar8 = (uint)*(byte *)(param_1 + 0x14);
  bVar1 = *(byte *)(param_1 + 0x1a);
  uVar11 = (ushort)(param_2 << 10);
  if (cVar2 == '\0') {
    if (0x1f < uVar8) {
      uVar8 = 0x1f;
    }
    uVar13 = (uint)bVar1 << 8;
    if ((uVar13 & 0xfffffeff) != 0) {
      r_assert_err(0,"sch_prog.c",0x107);
    }
    iVar6 = r_emi_get_mem_addr_by_offset(0);
    *(ushort *)(iVar6 + iVar9) = (ushort)(uVar8 << 0xb) | uVar11 | (ushort)uVar13 | 2;
  }
  else {
    bVar3 = *(byte *)(param_1 + 0x1b);
    if (0x1f < uVar8) {
      uVar8 = 0x1f;
    }
    uVar13 = (uint)*(byte *)(param_1 + 0x1e) << 9;
    if ((uVar13 & 0xfffffdff) != 0) {
      r_assert_err(0,"sch_prog.c",0x106);
    }
    uVar12 = (uint)bVar1 << 8;
    if ((uVar12 & 0xfffffeff) != 0) {
      r_assert_err(0,"sch_prog.c",0x107);
    }
    uVar5 = (uint)bVar3 << 7;
    if ((uVar5 & 0xffffff7f) != 0) {
      r_assert_err(0,"sch_prog.c",0x108);
    }
    iVar6 = r_emi_get_mem_addr_by_offset(0);
    *(ushort *)(iVar6 + iVar9) =
         (ushort)(uVar8 << 0xb) | uVar11 | (ushort)uVar13 | (ushort)uVar12 | (ushort)uVar5 | 0x42;
  }
  uVar8 = r_rwip_time_get();
  for (uVar13 = extraout_a1 + 0x15e; 0x270 < uVar13; uVar13 = uVar13 - 0x271) {
    uVar8 = uVar8 + 1 & 0xfffffff;
  }
  if (((*(uint *)(param_1 + 4) - uVar8 & 0xfffffff) < 0x7ffffff) &&
     ((*(uint *)(param_1 + 4) != uVar8 || (uVar13 <= *(uint *)(param_1 + 8))))) {
    _LANCHOR0 = 0;
    if ((bVar4 & 0xf0) != 0) {
      r_assert_err(0,"sch_prog.c",0x19f8);
    }
    _DAT_60031100 = uVar10 | 0x80000000;
  }
  else {
    _LANCHOR0 = 1;
    iVar6 = r_emi_get_mem_addr_by_offset(0);
    uVar11 = *(ushort *)(iVar6 + iVar9);
    iVar7 = r_emi_get_mem_addr_by_offset(0);
    iVar6 = _g_bt_plf_log_level;
    *(ushort *)(iVar7 + iVar9) = uVar11 & 0xffc7 | 0x30;
    if (0 < iVar6) {
      ets_printf("BLE_ERR_%d_%d_%d_%d\n",*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),
                 uVar8,uVar13);
      return;
    }
  }
  return;
}

