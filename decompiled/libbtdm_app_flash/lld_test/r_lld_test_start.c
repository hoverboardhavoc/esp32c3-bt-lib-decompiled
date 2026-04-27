/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app_flash -> lld_test.o -> r_lld_test_start
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_lld_test_start(char *param_1)

{
  char cVar1;
  byte bVar2;
  undefined2 uVar3;
  code *pcVar4;
  void *__s;
  undefined4 uVar5;
  int iVar6;
  undefined2 *puVar7;
  ushort *puVar8;
  int iVar9;
  void *__dest;
  ushort uVar10;
  uint uVar11;
  byte bStack_122;
  byte bStack_121;
  byte abStack_120 [264];
  
  if (_lld_test_env != (void *)0x0) {
    return 0xc;
  }
  __s = (void *)r_ke_malloc(0x2c,0);
  _lld_test_env = __s;
  if (__s == (void *)0x0) {
    r_assert_err(0x10000,799);
    return 0xc;
  }
  uVar5 = r_lld_read_clock();
  memset(__s,0,0x2c);
  *(code **)((int)__s + 0x20) = r_lld_test_evt_canceled_cbk;
  *(code **)((int)__s + 0x18) = r_lld_test_evt_start_cbk;
  bVar2 = DAT_00011019;
  *(code *)((int)__s + 0x16) = r_emi_get_mem_addr_by_offset;
  *(undefined4 *)((int)__s + 0x10) = 0x9c4;
  *(ushort *)((int)__s + 0x14) = bVar2 & 0xf | 0x6000;
  cVar1 = *param_1;
  *(char *)((int)__s + 0x26) = cVar1;
  *(char *)((int)__s + 0x27) = param_1[1];
  if (cVar1 == '\0') {
    _DAT_60031000 = _DAT_60031000 & 0xffffbfff | 0x4000;
    _DAT_600310d0 = _DAT_600310d0 & 0xf7ffffff | 0x8000000;
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
    *puVar7 = 0x1d;
    uVar11 = (uint)bStack_121;
    if ((uVar11 << 7 & 0xffffff7f) != 0) {
      r_assert_err(0,0x10000,0x82);
    }
    puVar8 = (ushort *)r_emi_get_mem_addr_by_offset(0x400);
    uVar10 = *puVar8;
    puVar8 = (ushort *)r_emi_get_mem_addr_by_offset(0x400);
    *puVar8 = uVar10 & 0xff7f | (ushort)(uVar11 << 7);
    uVar11 = (uint)abStack_120[0];
    if ((uVar11 << 6 & 0xffffffbf) != 0) {
      r_assert_err(0,0x10000,0x8e);
    }
    puVar8 = (ushort *)r_emi_get_mem_addr_by_offset(0x400);
    uVar10 = *puVar8;
    puVar8 = (ushort *)r_emi_get_mem_addr_by_offset(0x400);
    *puVar8 = uVar10 & 0xffbf | (ushort)(uVar11 << 6);
    iVar6 = r_emi_get_mem_addr_by_offset(0x400);
    *(undefined2 *)(iVar6 + 0x1a) = 0x8026;
    iVar6 = r_emi_get_mem_addr_by_offset(0x400);
    *(undefined2 *)(iVar6 + 0x28) = 0xff;
    iVar6 = r_emi_get_mem_addr_by_offset(0x400);
    pcVar4 = _r_emi_get_mem_addr_by_offset;
    *(undefined2 *)(iVar6 + 0x2a) = 0;
    (*pcVar4)(0,pcVar4);
  }
  else if (cVar1 == '\x01') {
    *(char *)((int)__s + 0x28) = param_1[2];
    *(char *)((int)__s + 0x29) = param_1[3];
    iVar6 = r_ble_util_buf_acl_tx_alloc(0xff);
    if (iVar6 == 0) {
      r_lld_test_cleanup();
      return 7;
    }
    *(short *)((int)__s + 0x24) = (short)iVar6;
    iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
    *(short *)(iVar9 + 4) = (short)iVar6;
    _DAT_60031000 = _DAT_60031000 & 0xffffbfff | 0x4000;
    _DAT_600310d0 = _DAT_600310d0 & 0xfffff7ff | 0x800;
    iVar6 = r_emi_get_mem_addr_by_offset(0x400);
    *(undefined2 *)(iVar6 + 0x44) = 0;
    iVar6 = r_emi_get_mem_addr_by_offset(0x400);
    *(undefined2 *)(iVar6 + 0x46) = 0;
    iVar6 = r_emi_get_mem_addr_by_offset(0x400);
    *(undefined2 *)(iVar6 + 0x48) = 0;
    uVar11 = (uint)(byte)param_1[3];
    if (uVar11 == 3) {
_L91:
      _DAT_600310d0 = (uVar11 & 1) << 0xd | _DAT_600310d0 & 0xffffcfff | 0x1000;
    }
    else {
      if (uVar11 < 4) {
        if (uVar11 == 0) goto _L91;
      }
      else if (3 < (uVar11 - 4 & 0xff)) {
        r_assert_err(0,0x10000,0x2c7);
        goto _L95;
      }
      bVar2 = param_1[2];
      switch(uVar11 - 1 & 0xff) {
      case 0:
        iVar6 = 0xf0;
        break;
      case 1:
        iVar6 = 0xaa;
        break;
      default:
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
      memset(abStack_120,iVar6,(uint)bVar2);
      __dest = (void *)r_emi_get_mem_addr_by_offset(*(undefined2 *)((int)__s + 0x24));
      memcpy(__dest,abStack_120,(uint)bVar2);
      _DAT_600310d0 = _DAT_600310d0 & 0xffffefff;
    }
_L95:
    bVar2 = param_1[3];
    uVar3 = *(undefined2 *)(param_1 + 2);
    if ((bVar2 & 0xf0) != 0) {
      r_assert_err(0,0x10000,0x126);
    }
    iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
    *(short *)(iVar6 + 2) = (short)CONCAT21(uVar3,bVar2);
    puVar8 = (ushort *)r_emi_get_mem_addr_by_offset(0x1400);
    uVar10 = *puVar8;
    puVar8 = (ushort *)r_emi_get_mem_addr_by_offset(0x1400);
    *puVar8 = (ushort)(((uint)uVar10 << 0x11) >> 0x11);
    iVar6 = r_emi_get_mem_addr_by_offset(0x400);
    *(undefined2 *)(iVar6 + 0x1c) = 0x1400;
    bStack_122 = 0;
    bStack_121 = 0;
    r_bt_rma_get_ant_by_act(0x1c,0,&bStack_122,&bStack_121);
    puVar7 = (undefined2 *)r_emi_get_mem_addr_by_offset(0x400);
    *puVar7 = 0x1c;
    uVar11 = (uint)bStack_122;
    if ((uVar11 << 7 & 0xffffff7f) != 0) {
      r_assert_err(0,0x10000,0x82);
    }
    puVar8 = (ushort *)r_emi_get_mem_addr_by_offset(0x400);
    uVar10 = *puVar8;
    puVar8 = (ushort *)r_emi_get_mem_addr_by_offset(0x400);
    *puVar8 = uVar10 & 0xff7f | (ushort)(uVar11 << 7);
    uVar11 = (uint)bStack_121;
    if ((uVar11 << 6 & 0xffffffbf) != 0) {
      r_assert_err(0,0x10000,0x8e);
    }
    puVar8 = (ushort *)r_emi_get_mem_addr_by_offset(0x400);
    uVar10 = *puVar8;
    puVar8 = (ushort *)r_emi_get_mem_addr_by_offset(0x400);
    *puVar8 = uVar10 & 0xffbf | (ushort)(uVar11 << 6);
    r_lld_test_set_tx_power(0,0x1c);
  }
  else {
    r_assert_err(0,0x10000,0x2f1);
  }
  iVar6 = r_emi_get_mem_addr_by_offset(0x400);
  *(undefined2 *)(iVar6 + 0xc) = 0x4129;
  iVar6 = r_emi_get_mem_addr_by_offset(0x400);
  *(undefined2 *)(iVar6 + 0xe) = 0x7176;
  iVar6 = r_emi_get_mem_addr_by_offset(0x400);
  *(undefined2 *)(iVar6 + 0x10) = 0x5555;
  iVar6 = r_emi_get_mem_addr_by_offset(0x400);
  *(undefined2 *)(iVar6 + 0x12) = 0x55;
  uVar11 = r_lld_test_freq2chnl(param_1[1]);
  if ((uVar11 & 0xffffffc0) != 0) {
    r_assert_err(0,0x10000,0x3cf);
  }
  iVar6 = r_emi_get_mem_addr_by_offset(0x400);
  uVar10 = *(ushort *)(iVar6 + 0x16);
  iVar6 = r_emi_get_mem_addr_by_offset(0x400);
  *(ushort *)(iVar6 + 0x16) = uVar10 & 0xffc0 | (ushort)uVar11;
  if (*param_1 == '\x01') {
    uVar10 = (byte)param_1[4] - 1 & 0xff;
  }
  else {
    if (*param_1 == '\0') {
      uVar11 = (byte)param_1[4] - 1 & 0xff;
      uVar10 = 0;
      goto _L108;
    }
    uVar10 = 0;
  }
  uVar11 = 0;
_L108:
  if ((uVar11 << 2 & 0xfffffff3) != 0) {
    r_assert_err(0,0x10000,399);
  }
  if ((uVar10 & 0xfffc) != 0) {
    r_assert_err(0,0x10000,400);
  }
  iVar6 = r_emi_get_mem_addr_by_offset(0x400);
  *(ushort *)(iVar6 + 4) = (ushort)(uVar11 << 2) | uVar10 | 0x1000;
  iVar6 = r_emi_get_mem_addr_by_offset(0x400);
  *(undefined2 *)(iVar6 + 0x4a) = 0;
  iVar6 = r_emi_get_mem_addr_by_offset(0x400);
  *(undefined2 *)(iVar6 + 0x4c) = 0;
  iVar6 = r_emi_get_mem_addr_by_offset(0x400);
  *(undefined2 *)(iVar6 + 0x4e) = 0;
  *(undefined4 *)((int)__s + 4) = uVar5;
  iVar6 = r_sch_arb_insert(__s);
  if (iVar6 != 0) {
    r_assert_err(0,0x10000,0x318);
    return 0;
  }
  *(undefined1 *)((int)__s + 0x2a) = 0;
  return 0;
}

