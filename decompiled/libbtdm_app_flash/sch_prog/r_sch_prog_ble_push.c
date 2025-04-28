/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
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
  uint uVar4;
  int iVar5;
  int extraout_a1;
  ushort uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  
  bVar3 = sch_prog_env;
  uVar8 = (uint)sch_prog_env;
  if (*(char *)(param_1 + 0x19) == '\0') {
    uVar6 = (ushort)*(byte *)(param_1 + 0x1c);
    if (uVar6 != 0) {
      uVar6 = (ushort)*(byte *)(param_1 + 0x1d);
    }
    uVar4 = (uint)*(byte *)(param_1 + 0x17) << 8;
    if ((uVar4 & 0xe000) != 0) {
      r_assert_err(0,"sch_prog.c",0x323);
    }
    if ((uVar6 & 0xfffc) != 0) {
      r_assert_err(0,"sch_prog.c",0x324);
    }
    iVar5 = r_emi_get_mem_addr_by_offset(0);
    iVar7 = uVar8 * 0x10;
    *(ushort *)(iVar7 + 0xe + iVar5) = (ushort)uVar4 | uVar6;
    bVar1 = *(byte *)(param_1 + 0x18);
    iVar5 = r_emi_get_mem_addr_by_offset(0);
    bVar2 = *(byte *)(param_1 + 0x1a);
    *(short *)(iVar7 + 8 + iVar5) = (short)((uint)bVar1 * 0x5a + 0x400 >> 1);
    uVar4 = (uint)*(byte *)(param_1 + 0x14);
    uVar6 = (ushort)(param_2 << 10);
    if (*(char *)(param_1 + 0x1c) == '\0') {
      if (0x1f < uVar4) {
        uVar4 = 0x1f;
      }
      uVar11 = (uint)bVar2 << 8;
      if ((uVar11 & 0xfffffeff) != 0) {
        r_assert_err(0,"sch_prog.c",0x107);
      }
      iVar5 = r_emi_get_mem_addr_by_offset(0);
      *(ushort *)(iVar5 + iVar7) = (ushort)(uVar4 << 0xb) | uVar6 | (ushort)uVar11 | 2;
    }
    else {
      bVar1 = *(byte *)(param_1 + 0x1b);
      if (0x1f < uVar4) {
        uVar4 = 0x1f;
      }
      uVar11 = (uint)*(byte *)(param_1 + 0x1e) << 9;
      if ((uVar11 & 0xfffffdff) != 0) {
        r_assert_err(0,"sch_prog.c",0x106);
      }
      uVar9 = (uint)bVar2 << 8;
      if ((uVar9 & 0xfffffeff) != 0) {
        r_assert_err(0,"sch_prog.c",0x107);
      }
      uVar10 = (uint)bVar1 << 7;
      if ((uVar10 & 0xffffff7f) != 0) {
        r_assert_err(0,"sch_prog.c",0x108);
      }
      iVar5 = r_emi_get_mem_addr_by_offset(0);
      *(ushort *)(iVar5 + iVar7) =
           (ushort)(uVar4 << 0xb) | uVar6 | (ushort)uVar11 | (ushort)uVar9 | (ushort)uVar10 | 0x42;
    }
    uVar4 = r_rwip_time_get();
    for (uVar11 = extraout_a1 + 0x15e; 0x270 < uVar11; uVar11 = uVar11 - 0x271) {
      uVar4 = uVar4 + 1 & 0xfffffff;
    }
    if (((*(uint *)(param_1 + 4) - uVar4 & 0xfffffff) < 0x7ffffff) &&
       ((*(uint *)(param_1 + 4) != uVar4 || (uVar11 <= *(uint *)(param_1 + 8))))) {
      kick_delay = 0;
      if ((bVar3 & 0xf0) != 0) {
        r_assert_err(0,"sch_prog.c",0x19f8);
      }
      _DAT_60031100 = uVar8 | 0x80000000;
      iVar5 = r_sdk_config_get_opts_ext();
      if ((*(uint *)(iVar5 + 0x28) & 1) != 0) {
        iVar5 = r_sdk_config_get_opts_ext();
        if (*(byte *)(iVar5 + 0x2c) < 2) {
          r_ble_log_internal_x2(0x20640006,uVar8,*(undefined4 *)(param_1 + 4));
          return;
        }
      }
    }
    else {
      kick_delay = 1;
      iVar5 = r_emi_get_mem_addr_by_offset(0);
      uVar6 = *(ushort *)(iVar5 + iVar7);
      iVar5 = r_emi_get_mem_addr_by_offset(0);
      *(ushort *)(iVar7 + iVar5) = uVar6 & 0xffc7 | 0x30;
      iVar5 = r_sdk_config_get_opts_ext();
      if ((*(uint *)(iVar5 + 0x28) & 1) != 0) {
        iVar5 = r_sdk_config_get_opts_ext();
        if (*(byte *)(iVar5 + 0x2c) < 4) {
          r_ble_log_internal_x2(0x60640007,*(undefined4 *)(param_1 + 4),uVar4);
        }
      }
      if (0 < _g_bt_plf_log_level) {
        ets_printf("BLE_ERR_%d_%d_%d_%d\n",*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8)
                   ,uVar4,uVar11);
        return;
      }
    }
  }
  return;
}

