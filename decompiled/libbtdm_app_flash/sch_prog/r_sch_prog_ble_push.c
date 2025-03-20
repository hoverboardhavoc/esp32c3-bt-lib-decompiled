/*
 * Last changed at upstream commit daab5dbba958a13041bd496e4a6ed506c9284a06
 * https://github.com/espressif/esp32c3-bt-lib/commit/daab5dbba958a13041bd496e4a6ed506c9284a06
 * Upstream date: 2025-03-20 20:43:40 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(86a4da5c)
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
  int extraout_a1;
  uint uVar7;
  int iVar8;
  uint uVar9;
  ushort uVar10;
  uint uVar11;
  uint uVar12;
  
  bVar4 = sch_prog_env;
  if (*(char *)(param_1 + 0x19) != '\0') {
    return;
  }
  uVar10 = (ushort)*(byte *)(param_1 + 0x1c);
  uVar9 = (uint)sch_prog_env;
  if (uVar10 != 0) {
    uVar10 = (ushort)*(byte *)(param_1 + 0x1d);
  }
  uVar7 = (uint)*(byte *)(param_1 + 0x17) << 8;
  if ((uVar7 & 0xe000) != 0) {
    r_assert_err(0,"sch_prog.c",0x323);
  }
  if ((uVar10 & 0xfffc) != 0) {
    r_assert_err(0,"sch_prog.c",0x324);
  }
  iVar6 = r_emi_get_mem_addr_by_offset(0);
  iVar8 = uVar9 * 0x10;
  *(ushort *)(iVar6 + iVar8 + 0xe) = (ushort)uVar7 | uVar10;
  bVar1 = *(byte *)(param_1 + 0x18);
  iVar6 = r_emi_get_mem_addr_by_offset(0);
  cVar2 = *(char *)(param_1 + 0x1c);
  *(short *)(iVar6 + iVar8 + 8) = (short)((uint)bVar1 * 0x5a + 0x400 >> 1);
  uVar7 = (uint)*(byte *)(param_1 + 0x14);
  bVar1 = *(byte *)(param_1 + 0x1a);
  uVar10 = (ushort)(param_2 << 10);
  if (cVar2 == '\0') {
    if (0x1f < uVar7) {
      uVar7 = 0x1f;
    }
    uVar12 = (uint)bVar1 << 8;
    if ((uVar12 & 0xfffffeff) != 0) {
      r_assert_err(0,"sch_prog.c",0x107);
    }
    iVar6 = r_emi_get_mem_addr_by_offset(0);
    *(ushort *)(iVar6 + iVar8) = (ushort)(uVar7 << 0xb) | uVar10 | (ushort)uVar12 | 2;
  }
  else {
    bVar3 = *(byte *)(param_1 + 0x1b);
    if (0x1f < uVar7) {
      uVar7 = 0x1f;
    }
    uVar12 = (uint)*(byte *)(param_1 + 0x1e) << 9;
    if ((uVar12 & 0xfffffdff) != 0) {
      r_assert_err(0,"sch_prog.c",0x106);
    }
    uVar11 = (uint)bVar1 << 8;
    if ((uVar11 & 0xfffffeff) != 0) {
      r_assert_err(0,"sch_prog.c",0x107);
    }
    uVar5 = (uint)bVar3 << 7;
    if ((uVar5 & 0xffffff7f) != 0) {
      r_assert_err(0,"sch_prog.c",0x108);
    }
    iVar6 = r_emi_get_mem_addr_by_offset(0);
    *(ushort *)(iVar6 + iVar8) =
         (ushort)(uVar7 << 0xb) | uVar10 | (ushort)uVar12 | (ushort)uVar11 | (ushort)uVar5 | 0x42;
  }
  uVar7 = r_rwip_time_get();
  for (uVar12 = extraout_a1 + 0x15e; 0x270 < uVar12; uVar12 = uVar12 - 0x271) {
    uVar7 = uVar7 + 1 & 0xfffffff;
  }
  if (((*(uint *)(param_1 + 4) - uVar7 & 0xfffffff) < 0x7ffffff) &&
     ((*(uint *)(param_1 + 4) != uVar7 || (uVar12 <= *(uint *)(param_1 + 8))))) {
    _LANCHOR0 = 0;
    if ((bVar4 & 0xf0) != 0) {
      r_assert_err(0,"sch_prog.c",0x19f8);
    }
    _DAT_60031100 = uVar9 | 0x80000000;
    iVar6 = r_sdk_config_get_opts_ext();
    if ((*(uint *)(iVar6 + 0x28) & 1) != 0) {
      iVar6 = r_sdk_config_get_opts_ext();
      if (*(byte *)(iVar6 + 0x2c) < 2) {
        r_ble_log_internal_x2(0x20640006,uVar9,*(undefined4 *)(param_1 + 4));
        return;
      }
    }
  }
  else {
    _LANCHOR0 = 1;
    iVar6 = r_emi_get_mem_addr_by_offset(0);
    uVar10 = *(ushort *)(iVar6 + iVar8);
    iVar6 = r_emi_get_mem_addr_by_offset(0);
    *(ushort *)(iVar6 + iVar8) = uVar10 & 0xffc7 | 0x30;
    iVar6 = r_sdk_config_get_opts_ext();
    if ((*(uint *)(iVar6 + 0x28) & 1) != 0) {
      iVar6 = r_sdk_config_get_opts_ext();
      if (*(byte *)(iVar6 + 0x2c) < 4) {
        r_ble_log_internal_x2(0x60640007,*(undefined4 *)(param_1 + 4),uVar7);
      }
    }
    if (0 < _g_bt_plf_log_level) {
      ets_printf("BLE_ERR_%d_%d_%d_%d\n",*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),
                 uVar7,uVar12);
      return;
    }
  }
  return;
}

