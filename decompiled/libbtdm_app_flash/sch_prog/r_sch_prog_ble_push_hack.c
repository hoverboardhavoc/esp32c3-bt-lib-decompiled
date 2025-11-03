/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> sch_prog.o -> r_sch_prog_ble_push_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_sch_prog_ble_push_hack(int param_1,int param_2)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  uint uVar4;
  int iVar5;
  int extraout_a1;
  int iVar6;
  uint uVar7;
  ushort uVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  
  bVar3 = sch_prog_env;
  uVar10 = (uint)sch_prog_env;
  if (*(char *)(param_1 + 0x19) == '\0') {
    uVar8 = (ushort)*(byte *)(param_1 + 0x1c);
    if (uVar8 != 0) {
      uVar8 = (ushort)*(byte *)(param_1 + 0x1d);
    }
    uVar4 = (uint)*(byte *)(param_1 + 0x17) << 8;
    if ((uVar4 & 0xe000) != 0) {
      r_assert_err(0,"sch_prog.c",0x323);
    }
    if ((uVar8 & 0xfffc) != 0) {
      r_assert_err(0,"sch_prog.c",0x324);
    }
    iVar5 = r_emi_get_mem_addr_by_offset(0);
    iVar9 = uVar10 * 0x10;
    *(ushort *)(iVar9 + 0xe + iVar5) = (ushort)uVar4 | uVar8;
    bVar1 = *(byte *)(param_1 + 0x18);
    iVar5 = r_emi_get_mem_addr_by_offset(0);
    bVar2 = *(byte *)(param_1 + 0x1a);
    *(short *)(iVar9 + 8 + iVar5) = (short)((uint)bVar1 * 0x5a + 0x400 >> 1);
    uVar4 = (uint)*(byte *)(param_1 + 0x14);
    uVar8 = (ushort)(param_2 << 10);
    if (*(char *)(param_1 + 0x1c) == '\0') {
      if (0x1f < uVar4) {
        uVar4 = 0x1f;
      }
      uVar13 = (uint)bVar2 << 8;
      if ((uVar13 & 0xfffffeff) != 0) {
        r_assert_err(0,"sch_prog.c",0x107);
      }
      iVar5 = r_emi_get_mem_addr_by_offset(0);
      *(ushort *)(iVar5 + iVar9) = (ushort)(uVar4 << 0xb) | uVar8 | (ushort)uVar13 | 2;
    }
    else {
      bVar1 = *(byte *)(param_1 + 0x1b);
      if (0x1f < uVar4) {
        uVar4 = 0x1f;
      }
      uVar13 = (uint)*(byte *)(param_1 + 0x1e) << 9;
      if ((uVar13 & 0xfffffdff) != 0) {
        r_assert_err(0,"sch_prog.c",0x106);
      }
      uVar11 = (uint)bVar2 << 8;
      if ((uVar11 & 0xfffffeff) != 0) {
        r_assert_err(0,"sch_prog.c",0x107);
      }
      uVar12 = (uint)bVar1 << 7;
      if ((uVar12 & 0xffffff7f) != 0) {
        r_assert_err(0,"sch_prog.c",0x108);
      }
      iVar5 = r_emi_get_mem_addr_by_offset(0);
      *(ushort *)(iVar5 + iVar9) =
           (ushort)(uVar4 << 0xb) | uVar8 | (ushort)uVar13 | (ushort)uVar11 | (ushort)uVar12 | 0x42;
    }
    uVar4 = r_rwip_time_get();
    for (uVar13 = extraout_a1 + 0x15e; 0x270 < uVar13; uVar13 = uVar13 - 0x271) {
      uVar4 = uVar4 + 1 & 0xfffffff;
    }
    if (((*(uint *)(param_1 + 4) - uVar4 & 0xfffffff) < 0x7ffffff) &&
       ((*(uint *)(param_1 + 4) != uVar4 || (uVar13 <= *(uint *)(param_1 + 8))))) {
      kick_delay = 0;
      if ((bVar3 & 0xf0) != 0) {
        r_assert_err(0,"sch_prog.c",0x19f8);
      }
      _DAT_60031100 = uVar10 | 0x80000000;
      uVar4 = *(uint *)(param_1 + 4) * 0x271;
      uVar10 = *(int *)(param_1 + 8) + uVar4;
      r_ble_log_internal_x3
                (0x406901a6,
                 uVar10 >> 1 |
                 ((uint)(uVar10 < uVar4) + (int)((ulonglong)*(uint *)(param_1 + 4) * 0x271 >> 0x20))
                 * -0x80000000,*(undefined4 *)(param_1 + 0xc),
                 CONCAT11(*(undefined1 *)(param_1 + 0x18),bVar3));
      return;
    }
    kick_delay = 1;
    iVar5 = r_emi_get_mem_addr_by_offset(0);
    uVar8 = *(ushort *)(iVar5 + iVar9);
    iVar5 = r_emi_get_mem_addr_by_offset(0);
    uVar12 = *(uint *)(param_1 + 4);
    iVar6 = *(int *)(param_1 + 8);
    uVar7 = uVar12 * 0x271;
    *(ushort *)(iVar9 + iVar5) = uVar8 & 0xffc7 | 0x30;
    uVar11 = iVar6 + uVar7;
    uVar10 = uVar4 * 0x271 + uVar13;
    r_ble_log_internal_x2
              (0x606901a5,
               uVar10 >> 1 |
               ((uint)(uVar10 < uVar4 * 0x271) + (int)((ulonglong)uVar4 * 0x271 >> 0x20)) *
               -0x80000000,
               uVar11 >> 1 |
               ((uint)(uVar11 < uVar7) + (int)((ulonglong)uVar12 * 0x271 >> 0x20)) * -0x80000000);
    if (0 < _g_bt_plf_log_level) {
      ets_printf("BLE_ERR_%d_%d_%d_%d\n",*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),
                 uVar4,uVar13);
      return;
    }
  }
  return;
}

