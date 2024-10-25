/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> hci_tl.o -> r_hci_tx_start
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_hci_tx_start(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  code *pcVar4;
  undefined1 uVar5;
  
  iVar1 = _hci_tl_env;
  if (_hci_tl_env == 0) {
    iVar1 = (**(code **)(_r_ip_funcs_p + 0xb8))(*(code **)(_r_ip_funcs_p + 0xb8));
    if (iVar1 == 0) {
      DAT_0001201e = 1;
      return;
    }
    DAT_0001201e = 0;
    iVar1 = _r_modules_funcs_p;
    if (_r_modules_funcs_p == 0) {
      DAT_0001201e = 0;
      return;
    }
  }
  _memcmp = iVar1;
  switch(*(short *)(iVar1 + 4) + -0x1101) {
  case 0:
    if (((*(short *)(iVar1 + 8) != 0xc03) && (*(short *)(iVar1 + 8) != 0xc35)) &&
       (iVar2 = (DAT_0001201d + 1) * 0x1000000, DAT_0001201d = (byte)((uint)iVar2 >> 0x18),
       5 < iVar2 >> 0x18)) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"hci_tl.c",0x428,*(code **)(_r_plf_funcs_p + 8));
    }
    pcVar4 = *(code **)(_r_ip_funcs_p + 0x14);
    break;
  case 1:
    iVar2 = (DAT_0001201d + 1) * 0x1000000;
    DAT_0001201d = (byte)((uint)iVar2 >> 0x18);
    if (5 < iVar2 >> 0x18) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"hci_tl.c",0x437,*(code **)(_r_plf_funcs_p + 8));
    }
    pcVar4 = *(code **)(_r_ip_funcs_p + 0x18);
    break;
  case 2:
    pcVar4 = *(code **)(_r_ip_funcs_p + 0x20);
    break;
  case 3:
    pcVar4 = *(code **)(_r_ip_funcs_p + 0x24);
    break;
  default:
    (**(code **)(_r_plf_funcs_p + 0xc))(0,"hci_tl.c",0x4a0,*(code **)(_r_plf_funcs_p + 0xc));
    uVar5 = 0;
    uVar3 = 0;
    iVar1 = 0;
    goto _L127;
  case 5:
    uVar5 = 2;
    iVar1 = (**(code **)(_r_ip_funcs_p + 0x10))(iVar1,*(code **)(_r_ip_funcs_p + 0x10));
    uVar3 = *(ushort *)(iVar1 + 2) + 4 & 0xffff;
    goto _L127;
  }
  iVar1 = (*pcVar4)(iVar1,pcVar4);
  uVar5 = 4;
  uVar3 = *(byte *)(iVar1 + 1) + 2;
_L127:
  memcpy = (code)0x0;
  iVar2 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  if (*(char *)(iVar2 + 0x17) != '\x01') {
                    /* WARNING: Could not recover jumptable at 0x00010920. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_modules_funcs_p + 0x88))(uVar5,iVar1,*(undefined4 *)(_r_ip_funcs_p + 100));
    return;
  }
  *(undefined1 *)(iVar1 + -1) = uVar5;
  (**(code **)(_r_plf_funcs_p + 0xe0))(iVar1 + -1,uVar3 + 1,*(code **)(_r_plf_funcs_p + 0xe0));
                    /* WARNING: Could not recover jumptable at 0x0001086a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_modules_funcs_p + 0x108))(5);
  return;
}

