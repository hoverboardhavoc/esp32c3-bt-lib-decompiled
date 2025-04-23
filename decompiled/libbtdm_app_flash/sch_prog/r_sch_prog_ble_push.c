/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
  byte bVar2;
  byte bVar3;
  ushort uVar4;
  int iVar5;
  int extraout_a1;
  uint uVar6;
  ushort uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  
  if (*(char *)(param_1 + 0x19) != '\0') {
    return;
  }
  uVar7 = (ushort)*(byte *)(param_1 + 0x1c);
  uVar9 = (uint)sch_prog_env;
  bVar1 = *(byte *)(param_1 + 0x17);
  if (uVar7 != 0) {
    uVar7 = (ushort)*(byte *)(param_1 + 0x1d);
  }
  if ((bVar1 & 0xe0) != 0) {
    r_assert_err(0,"sch_prog.c",0x323);
  }
  if (3 < uVar7) {
    r_assert_err(0,"sch_prog.c",0x324);
  }
  iVar5 = r_emi_get_mem_addr_by_offset(0);
  iVar8 = uVar9 * 0x10;
  *(ushort *)(iVar8 + 0xe + iVar5) = (ushort)bVar1 << 8 | uVar7;
  bVar1 = *(byte *)(param_1 + 0x18);
  iVar5 = r_emi_get_mem_addr_by_offset(0);
  *(short *)(iVar8 + 8 + iVar5) = (short)((uint)bVar1 * 0x5a >> 1) + 0x200;
  uVar6 = (uint)*(byte *)(param_1 + 0x14);
  if (0x1f < uVar6) {
    uVar6 = 0x1f;
  }
  bVar1 = *(byte *)(param_1 + 0x1a);
  uVar7 = (ushort)(uVar6 << 0xb);
  uVar4 = (ushort)(param_2 << 10);
  if (*(char *)(param_1 + 0x1c) == '\0') {
    if ((bVar1 & 0xfe) != 0) {
      r_assert_err(0,"sch_prog.c",0x107);
    }
    iVar5 = r_emi_get_mem_addr_by_offset(0);
    *(ushort *)(iVar5 + iVar8) = uVar7 | uVar4 | (ushort)bVar1 << 8 | 2;
  }
  else {
    bVar2 = *(byte *)(param_1 + 0x1e);
    bVar3 = *(byte *)(param_1 + 0x1b);
    if ((bVar2 & 0xfe) != 0) {
      r_assert_err(0,"sch_prog.c",0x106);
    }
    if ((bVar1 & 0xfe) != 0) {
      r_assert_err(0,"sch_prog.c",0x107);
    }
    if ((bVar3 & 0xfe) != 0) {
      r_assert_err(0,"sch_prog.c",0x108);
    }
    iVar5 = r_emi_get_mem_addr_by_offset(0);
    *(ushort *)(iVar5 + iVar8) =
         uVar7 | uVar4 | (ushort)bVar2 << 9 | (ushort)bVar1 << 8 | (ushort)bVar3 << 7 | 0x42;
  }
  uVar6 = r_rwip_time_get();
  for (uVar10 = extraout_a1 + 0x15e; 0x270 < uVar10; uVar10 = uVar10 - 0x271) {
    uVar6 = uVar6 + 1 & 0xfffffff;
  }
  if (((*(uint *)(param_1 + 4) - uVar6 & 0xfffffff) < 0x7ffffff) &&
     ((uVar6 != *(uint *)(param_1 + 4) || (uVar10 <= *(uint *)(param_1 + 8))))) {
    kick_delay = 0;
    if (0xf < uVar9) {
      r_assert_err(0,"sch_prog.c",0x19f8);
    }
    _DAT_60031100 = uVar9 | 0x80000000;
    iVar5 = r_sdk_config_get_opts_ext();
    if ((*(uint *)(iVar5 + 0x28) & 1) != 0) {
      iVar5 = r_sdk_config_get_opts_ext();
      if (*(byte *)(iVar5 + 0x2c) < 2) {
        r_ble_log_internal_x2(0x20640006,uVar9,*(undefined4 *)(param_1 + 4));
        return;
      }
    }
  }
  else {
    kick_delay = 1;
    iVar5 = r_emi_get_mem_addr_by_offset(0);
    uVar7 = *(ushort *)(iVar5 + iVar8);
    iVar5 = r_emi_get_mem_addr_by_offset(0);
    *(ushort *)(iVar8 + iVar5) = uVar7 & 0xffc7 | 0x30;
    iVar5 = r_sdk_config_get_opts_ext();
    if ((*(uint *)(iVar5 + 0x28) & 1) != 0) {
      iVar5 = r_sdk_config_get_opts_ext();
      if (*(byte *)(iVar5 + 0x2c) < 4) {
        r_ble_log_internal_x2(0x60640007,*(undefined4 *)(param_1 + 4),uVar6);
      }
    }
    if (0 < _g_bt_plf_log_level) {
      ets_printf("BLE_ERR_%d_%d_%d_%d\n",*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),
                 uVar6,uVar10);
      return;
    }
  }
  return;
}

