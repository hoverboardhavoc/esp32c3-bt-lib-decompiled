/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_test.o -> r_lld_test_start
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_lld_test_start(byte *param_1)

{
  byte bVar1;
  undefined2 uVar2;
  code *pcVar3;
  byte bVar4;
  void *__s;
  undefined4 uVar5;
  int iVar6;
  undefined2 *puVar7;
  ushort *puVar8;
  uint uVar9;
  int iVar10;
  void *__dest;
  ushort uVar11;
  byte bStack_122;
  byte bStack_121;
  byte abStack_120 [264];
  
  if (_lld_test_env != (void *)0x0) {
    return 0xc;
  }
  __s = (void *)r_ke_malloc(0x2c,0);
  _lld_test_env = __s;
  if (__s == (void *)0x0) {
    r_assert_err(0x10000,0x31b);
    return 0xc;
  }
  uVar5 = r_lld_read_clock();
  memset(__s,0,0x2c);
  *(code **)((int)__s + 0x20) = r_lld_test_evt_canceled_cbk;
  *(code **)((int)__s + 0x18) = r_lld_test_evt_start_cbk;
  bVar1 = DAT_0001101d;
  *(code *)((int)__s + 0x16) = r_emi_get_mem_addr_by_offset;
  *(undefined4 *)((int)__s + 0x10) = 0x9c4;
  *(ushort *)((int)__s + 0x14) = bVar1 & 0xf | 0x6000;
  bVar1 = *param_1;
  *(byte *)((int)__s + 0x26) = bVar1;
  *(byte *)((int)__s + 0x27) = param_1[1];
  if (bVar1 == 0) {
    _DAT_60031000 = _DAT_60031000 | 0x4000;
    _DAT_600310d0 = _DAT_600310d0 | 0x8000000;
    iVar6 = r_emi_get_mem_addr_by_offset(0x400);
    *(undefined2 *)(iVar6 + 0x4a) = 0;
    iVar6 = r_emi_get_mem_addr_by_offset(0x400);
    *(undefined2 *)(iVar6 + 0x4c) = 0;
    iVar6 = r_emi_get_mem_addr_by_offset(0x400);
    *(undefined2 *)(iVar6 + 0x4e) = 0;
    bStack_121 = 0;
    abStack_120[0] = 0;
    r_bt_rma_get_ant_by_act(0x1d,0,&bStack_121,abStack_120);
    puVar7 = (undefined2 *)r_emi_get_mem_addr_by_offset(0x400);
    bVar1 = bStack_121;
    *puVar7 = 0x1d;
    if ((bStack_121 & 0xfe) != 0) {
      r_assert_err(0,0x10000,0x82);
    }
    puVar8 = (ushort *)r_emi_get_mem_addr_by_offset(0x400);
    uVar11 = *puVar8;
    puVar8 = (ushort *)r_emi_get_mem_addr_by_offset(0x400);
    bVar4 = abStack_120[0];
    *puVar8 = uVar11 & 0xff7f | (ushort)bVar1 << 7;
    if ((abStack_120[0] & 0xfe) != 0) {
      r_assert_err(0,0x10000,0x8e);
    }
    puVar8 = (ushort *)r_emi_get_mem_addr_by_offset(0x400);
    uVar11 = *puVar8;
    puVar8 = (ushort *)r_emi_get_mem_addr_by_offset(0x400);
    *puVar8 = uVar11 & 0xffbf | (ushort)bVar4 << 6;
    iVar6 = r_emi_get_mem_addr_by_offset(0x400);
    *(undefined2 *)(iVar6 + 0x1a) = 0x8026;
    iVar6 = r_emi_get_mem_addr_by_offset(0x400);
    *(undefined2 *)(iVar6 + 0x28) = 0xff;
    iVar6 = r_emi_get_mem_addr_by_offset(0x400);
    pcVar3 = _r_emi_get_mem_addr_by_offset;
    *(undefined2 *)(iVar6 + 0x2a) = 0;
    (*pcVar3)(0,pcVar3);
    goto _L103;
  }
  if (bVar1 != 1) {
    r_assert_err(0,0x10000,0x2ed);
    goto _L103;
  }
  *(byte *)((int)__s + 0x28) = param_1[2];
  *(byte *)((int)__s + 0x29) = param_1[3];
  iVar6 = r_ble_util_buf_acl_tx_alloc(0xff);
  if (iVar6 == 0) {
    r_lld_test_cleanup();
    return 7;
  }
  *(short *)((int)__s + 0x24) = (short)iVar6;
  iVar10 = r_emi_get_mem_addr_by_offset(0x1400);
  *(short *)(iVar10 + 4) = (short)iVar6;
  _DAT_60031000 = _DAT_60031000 | 0x4000;
  _DAT_600310d0 = _DAT_600310d0 | 0x800;
  iVar6 = r_emi_get_mem_addr_by_offset(0x400);
  *(undefined2 *)(iVar6 + 0x44) = 0;
  iVar6 = r_emi_get_mem_addr_by_offset(0x400);
  *(undefined2 *)(iVar6 + 0x46) = 0;
  iVar6 = r_emi_get_mem_addr_by_offset(0x400);
  *(undefined2 *)(iVar6 + 0x48) = 0;
  uVar9 = (uint)param_1[3];
  if (uVar9 == 3) {
_L106:
    _DAT_600310d0 = (uVar9 & 1) << 0xd | _DAT_600310d0 & 0xffffdfff | 0x1000;
  }
  else {
    if (uVar9 < 4) {
      if (uVar9 == 0) goto _L106;
    }
    else if (3 < (uVar9 - 4 & 0xff)) {
      r_assert_err(0,0x10000,0x2c3);
      goto _L110;
    }
    bVar1 = param_1[2];
    switch(uVar9 - 1 & 0xff) {
    case 0:
      iVar6 = 0xf0;
      break;
    case 1:
      iVar6 = 0xaa;
      break;
    default:
      if (7 < uVar9) {
        r_assert_err(0,0x10000,0x16f);
      }
    case 4:
      iVar6 = 0;
      break;
    case 3:
      iVar6 = 0xff;
      break;
    case 5:
      iVar6 = 0xf;
      break;
    case 6:
      iVar6 = 0x55;
    }
    memset(abStack_120,iVar6,(uint)bVar1);
    bVar1 = param_1[2];
    __dest = (void *)r_emi_get_mem_addr_by_offset(*(undefined2 *)((int)__s + 0x24));
    memcpy(__dest,abStack_120,(uint)bVar1);
    _DAT_600310d0 = _DAT_600310d0 & 0xffffefff;
  }
_L110:
  bVar1 = param_1[3];
  uVar2 = *(undefined2 *)(param_1 + 2);
  if (0xf < bVar1) {
    r_assert_err(0,0x10000,0x126);
  }
  iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
  *(short *)(iVar6 + 2) = (short)CONCAT21(uVar2,bVar1);
  puVar8 = (ushort *)r_emi_get_mem_addr_by_offset(0x1400);
  uVar11 = *puVar8;
  puVar8 = (ushort *)r_emi_get_mem_addr_by_offset(0x1400);
  *puVar8 = (ushort)(((uint)uVar11 << 0x11) >> 0x11);
  iVar6 = r_emi_get_mem_addr_by_offset(0x400);
  *(undefined2 *)(iVar6 + 0x1c) = 0x1400;
  bStack_122 = 0;
  bStack_121 = 0;
  r_bt_rma_get_ant_by_act(0x1c,0,&bStack_122,&bStack_121);
  puVar7 = (undefined2 *)r_emi_get_mem_addr_by_offset(0x400);
  bVar1 = bStack_122;
  *puVar7 = 0x1c;
  if ((bStack_122 & 0xfe) != 0) {
    r_assert_err(0,0x10000,0x82);
  }
  puVar8 = (ushort *)r_emi_get_mem_addr_by_offset(0x400);
  uVar11 = *puVar8;
  puVar8 = (ushort *)r_emi_get_mem_addr_by_offset(0x400);
  bVar4 = bStack_121;
  *puVar8 = uVar11 & 0xff7f | (ushort)bVar1 << 7;
  if ((bStack_121 & 0xfe) != 0) {
    r_assert_err(0,0x10000,0x8e);
  }
  puVar8 = (ushort *)r_emi_get_mem_addr_by_offset(0x400);
  uVar11 = *puVar8;
  puVar8 = (ushort *)r_emi_get_mem_addr_by_offset(0x400);
  *puVar8 = uVar11 & 0xffbf | (ushort)bVar4 << 6;
  r_lld_test_set_tx_power(0,0x1c);
_L103:
  iVar6 = r_emi_get_mem_addr_by_offset(0x400);
  *(undefined2 *)(iVar6 + 0xc) = 0x4129;
  iVar6 = r_emi_get_mem_addr_by_offset(0x400);
  *(undefined2 *)(iVar6 + 0xe) = 0x7176;
  iVar6 = r_emi_get_mem_addr_by_offset(0x400);
  *(undefined2 *)(iVar6 + 0x10) = 0x5555;
  iVar6 = r_emi_get_mem_addr_by_offset(0x400);
  *(undefined2 *)(iVar6 + 0x12) = 0x55;
  uVar9 = r_lld_test_freq2chnl(param_1[1]);
  if (0x3f < uVar9) {
    r_assert_err(0,0x10000,0x3cf);
  }
  iVar6 = r_emi_get_mem_addr_by_offset(0x400);
  uVar11 = *(ushort *)(iVar6 + 0x16);
  iVar6 = r_emi_get_mem_addr_by_offset(0x400);
  *(ushort *)(iVar6 + 0x16) = (ushort)uVar9 | uVar11 & 0xffc0;
  bVar1 = *param_1;
  uVar11 = (ushort)bVar1;
  if (bVar1 == 1) {
    uVar11 = param_1[4] - 1 & 0xff;
    if (3 < uVar11) {
      r_assert_err(0,0x10000,400);
    }
    uVar9 = 0;
  }
  else if (bVar1 == 0) {
    uVar9 = (uint)(byte)(param_1[4] - 1);
    if ((param_1[4] - 1 & 0xfc) != 0) {
      r_assert_err(0,0x10000,399);
    }
  }
  else {
    uVar9 = 0;
    uVar11 = 0;
  }
  iVar6 = r_emi_get_mem_addr_by_offset(0x400);
  *(ushort *)(iVar6 + 4) = (ushort)(uVar9 << 2) | uVar11 | 0x1000;
  iVar6 = r_emi_get_mem_addr_by_offset(0x400);
  *(undefined2 *)(iVar6 + 0x4a) = 0;
  iVar6 = r_emi_get_mem_addr_by_offset(0x400);
  *(undefined2 *)(iVar6 + 0x4c) = 0;
  iVar6 = r_emi_get_mem_addr_by_offset(0x400);
  *(undefined2 *)(iVar6 + 0x4e) = 0;
  *(undefined4 *)((int)__s + 4) = uVar5;
  iVar6 = r_sch_arb_insert(__s);
  if (iVar6 == 0) {
    *(undefined1 *)((int)__s + 0x2a) = 0;
  }
  else {
    r_assert_err(0,0x10000,0x314);
  }
  return 0;
}

