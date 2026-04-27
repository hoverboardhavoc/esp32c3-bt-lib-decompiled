/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app_flash -> lld_init.o -> r_lld_init_evt_canceled_cbk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x00010802) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_init_evt_canceled_cbk(int param_1)

{
  byte bVar1;
  int iVar2;
  ushort uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  byte bVar9;
  uint uVar10;
  
  if (param_1 == 0) {
    uVar7 = 0x5f1;
_L95:
    r_assert_err(0,0x10000,uVar7);
    return;
  }
  r_ble_log_internal_x1
            (0x4042012a,
             (uint)*(byte *)(param_1 + 0x52) |
             (uint)*(byte *)(param_1 + 0x31) << 8 | (uint)*(byte *)(param_1 + 0x16) << 0x10);
  if (*(char *)(param_1 + 0x31) != '\0') {
    r_assert_param(*(undefined1 *)(param_1 + 0x51),0x10000,0x5ec);
    return;
  }
  iVar6 = r_lld_read_clock();
  bVar1 = rwip_priority;
  if ((uint)*(ushort *)(param_1 + 0x2c) << 1 <= (iVar6 - *(int *)(param_1 + 0x28) & 0xfffffffU)) {
    if (0xff < (uint)*(byte *)(param_1 + 0x16) + (uint)rwip_priority) {
      r_assert_err(0,0x10000,0x5d3);
    }
    *(int *)(param_1 + 0x28) = iVar6;
    *(byte *)(param_1 + 0x16) = bVar1 + *(char *)(param_1 + 0x16);
  }
  if (*(char *)(param_1 + 0x3d) != '\x01') {
    iVar6 = r_sch_arb_insert(param_1);
    if (iVar6 == 0) {
      return;
    }
    uVar7 = 0x5df;
    goto _L95;
  }
  *(undefined1 *)(param_1 + 0x3d) = 0;
  iVar2 = *(int *)(_lld_init_env + (uint)*(byte *)(param_1 + 0x51) * 4);
  iVar5 = r_lld_read_clock();
  bVar1 = *(byte *)(iVar2 + 0x52);
  uVar4 = (iVar5 - iVar6 & 0xfffffffU) + 1 >> 1;
  if (*(char *)(iVar2 + 0x3d) == '\x01') {
    r_sch_slice_bg_remove(1);
    *(undefined4 *)(iVar2 + 4) = *(undefined4 *)(iVar2 + 0x40);
    *(undefined4 *)(iVar2 + 8) = *(undefined4 *)(iVar2 + 0x44);
    *(uint *)(iVar2 + 0x10) =
         ((uint)*(ushort *)(&lld_init_max_aux_dur_tab + (uint)*(byte *)(iVar2 + 0x4d) * 2) +
         *(int *)(iVar2 + 0x48)) * 2 + (uint)_sdk_cfg_priv_opts;
    bVar9 = DAT_00013042;
    if (DAT_00013042 < *(byte *)(iVar2 + 0x16)) {
      bVar9 = *(byte *)(iVar2 + 0x16);
    }
    *(byte *)(iVar2 + 0x16) = bVar9;
    *(ushort *)(iVar2 + 0x14) = DAT_00013043 & 0xf | 0x2000;
    iVar6 = r_sch_arb_insert(iVar2);
    if (iVar6 == 0) {
      uVar10 = (uint)*(byte *)(iVar2 + 0x4d);
      uVar4 = *(uint *)(iVar2 + 0x48);
      *(char *)(iVar2 + 0x3e) = (1 < uVar10) + '\x02';
      if ((uVar10 << 4 & 0xffffffcf) != 0) {
        r_assert_err(0x10000,0x1bf);
      }
      iVar5 = (uint)bVar1 * 0x5a;
      iVar6 = r_emi_get_mem_addr_by_offset(0x400);
      uVar3 = *(ushort *)(iVar6 + iVar5 + 4);
      iVar6 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar6 + iVar5 + 4) = uVar3 & 0xffcf | (ushort)(uVar10 << 4);
      uVar3 = *(ushort *)(&lld_init_max_aux_dur_tab + uVar10 * 2);
      iVar6 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar5 + 0x20 + iVar6) = (ushort)(((uint)uVar3 + uVar4 + 0x270) / 0x271) & 0xff;
      if (uVar4 < 0x4000) {
        iVar6 = r_emi_get_mem_addr_by_offset(0x400);
        uVar3 = (ushort)(uVar4 + 1 >> 1);
      }
      else {
        iVar6 = r_emi_get_mem_addr_by_offset(0x400);
        uVar3 = (ushort)((uVar4 + 0x270) / 0x271) & 0xff | 0x8000;
      }
      *(ushort *)(iVar6 + iVar5 + 0x1a) = uVar3;
      uVar4 = (uint)*(byte *)(iVar2 + 0x4c) << 10;
      if ((uVar4 & 0x30000) != 0) {
        r_assert_err(0,0x10000,0x635);
      }
      iVar6 = r_emi_get_mem_addr_by_offset(0x400);
      uVar3 = *(ushort *)(iVar6 + iVar5 + 0x26);
      iVar6 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar6 + iVar5 + 0x26) = uVar3 & 0x3ff | (ushort)uVar4;
      goto _L84;
    }
    *(undefined1 *)(iVar2 + 0x3d) = 0;
  }
  if (uVar4 < *(uint *)(iVar2 + 0x24)) {
    uVar4 = *(uint *)(iVar2 + 0x24) - uVar4;
  }
  else {
    r_sch_slice_bg_remove(1);
    uVar4 = (uint)*(ushort *)(iVar2 + 0x2e);
    uVar10 = _sch_slice_params;
    if (_sch_slice_params == 0xffffffff) {
      uVar10 = (*(ushort *)(iVar2 + 0x2c) - uVar4) * 2 + iVar5 & 0xffffffc;
    }
    *(uint *)(iVar2 + 4) = uVar10;
    *(undefined4 *)(iVar2 + 8) = 0;
  }
  uVar8 = (uint)_r_assert_param;
  *(uint *)(iVar2 + 0x24) = uVar4;
  uVar10 = uVar4 * 0x4e2;
  if (uVar8 < uVar4 * 0x4e2) {
    uVar10 = uVar8;
  }
  *(uint *)(iVar2 + 0x10) = uVar10;
  iVar5 = (uint)bVar1 * 0x5a;
  *(ushort *)(iVar2 + 0x14) = DAT_00013047 & 0xf | 0x6000;
  *(undefined1 *)(iVar2 + 0x3e) = 1;
  iVar6 = r_emi_get_mem_addr_by_offset(0x400);
  *(short *)(iVar5 + 0x20 + iVar6) = (short)uVar4;
  uVar4 = *(uint *)(iVar2 + 0x24);
  if ((uVar4 >> 0xf & 1) != 0) {
    r_assert_err(0,0x10000,0x4ab);
  }
  iVar6 = r_emi_get_mem_addr_by_offset(0x400);
  *(ushort *)(iVar5 + 0x1a + iVar6) = (ushort)uVar4 | 0x8000;
  iVar6 = r_emi_get_mem_addr_by_offset(0x400);
  *(undefined2 *)(iVar5 + 0x46 + iVar6) = 0;
  iVar6 = r_sch_arb_insert(iVar2);
  if (iVar6 != 0) {
    r_assert_err(0,0x10000,0x280);
    return;
  }
_L84:
  *(undefined1 *)(iVar2 + 0x50) = 0;
  return;
}

