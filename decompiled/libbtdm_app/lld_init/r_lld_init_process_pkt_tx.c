/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> lld_init.o -> r_lld_init_process_pkt_tx
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_init_process_pkt_tx(int param_1)

{
  byte bVar1;
  short sVar2;
  short sVar3;
  ushort uVar4;
  int iVar5;
  int iVar6;
  undefined1 *__s;
  undefined4 uVar7;
  void *pvVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  
  iVar10 = _lld_init_env;
  iVar12 = *(int *)(param_1 * 4 + _lld_init_env);
  bVar1 = *(byte *)(_lld_init_env + 0x2c);
  iVar5 = (**(code **)(_r_ip_funcs_p + 0x840))(1,param_1,*(code **)(_r_ip_funcs_p + 0x840));
  if (iVar5 != 0) {
    return;
  }
  iVar5 = ((uint)bVar1 * 9 & 0xff) * 0xe;
  if (*(char *)(iVar10 + 0x50) != '\0') {
    iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    if ((*(short *)(iVar6 + iVar5) < 0) &&
       (iVar6 = (**(code **)(_r_ip_funcs_p + 0x7b4))(*(code **)(_r_ip_funcs_p + 0x7b4)), iVar6 == 0)
       ) {
      __s = (undefined1 *)
            (**(code **)(_r_modules_funcs_p + 200))
                      (0x209,0,0xff,0x38,*(code **)(_r_modules_funcs_p + 200));
      bVar1 = (&co_rate_to_phy)[*(byte *)(iVar10 + 0x4e)];
      uVar7 = (**(code **)(_r_ip_funcs_p + 0x488))(param_1,*(code **)(_r_ip_funcs_p + 0x488));
      memset(__s,0,0x38);
      __s[0x20] = *(byte *)(iVar10 + 0x33) & 1;
      uVar11 = (uint)*(ushort *)(iVar10 + 0x4c);
      if (uVar11 == 0) {
        memcpy(__s + 0xe,(void *)(iVar12 + 0x32),6);
      }
      else {
        pvVar8 = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))
                                   (uVar11 + 0x18 & 0xffff,*(code **)(_r_plf_funcs_p + 0xbc));
        memcpy(__s + 0xe,pvVar8,6);
        iVar6 = ((uVar11 - 0xc60) / 0x34 & 0xff) * 0x34;
        if (((*(byte *)(iVar10 + 0x32) & 2) != 0) &&
           (iVar9 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc60,*(code **)(_r_plf_funcs_p + 0xbc)),
           (*(ushort *)(iVar9 + iVar6) >> 7 & 1) != 0)) {
          pvVar8 = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))
                                     (*(short *)(iVar10 + 0x4c) + 0x2e,
                                      *(code **)(_r_plf_funcs_p + 0xbc));
          memcpy(__s + 2,pvVar8,6);
        }
        iVar9 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc60,*(code **)(_r_plf_funcs_p + 0xbc));
        if ((*(ushort *)(iVar9 + iVar6) >> 3 & 1) != 0) {
          pvVar8 = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))
                                     (*(short *)(iVar10 + 0x4c) + 0x12,
                                      *(code **)(_r_plf_funcs_p + 0xbc));
          memcpy(__s + 8,pvVar8,6);
          iVar9 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc60,*(code **)(_r_plf_funcs_p + 0xbc));
          __s[0x20] = (byte)*(undefined2 *)(iVar9 + iVar6) & 1 | 2;
        }
      }
      memcpy(__s + 0x14,(void *)(iVar10 + 0x34),4);
      iVar6 = (uint)bVar1 * 10 + iVar10;
      *(undefined2 *)(__s + 0x18) = *(undefined2 *)(iVar6 + 2);
      *(undefined2 *)(__s + 0x1a) = *(undefined2 *)(iVar6 + 4);
      memcpy(__s + 0x21,(void *)(iVar10 + 0x2d),5);
      __s[0x26] = *(undefined1 *)(iVar6 + 10);
      __s[0x27] = *(undefined1 *)(iVar10 + 0x4e);
      *(undefined2 *)(__s + 0x28) = *(undefined2 *)(iVar6 + 6);
      *(undefined2 *)(__s + 0x2a) = *(undefined2 *)(iVar6 + 8);
      memcpy(__s + 0x2c,(void *)(iVar10 + 0x38),3);
      __s[0x2f] = *(undefined1 *)(iVar10 + 0x3b);
      __s[0x30] = *(undefined1 *)(iVar10 + 0x3c);
      __s[0x31] = *(undefined1 *)(iVar10 + 0x3d);
      sVar2 = *(short *)(iVar12 + 0x38);
      sVar3 = *(short *)(iVar12 + 0x3a);
      *(undefined4 *)(__s + 0x1c) = uVar7;
      __s[0x33] = sVar2 != sVar3;
      __s[0x34] = *(undefined1 *)(iVar10 + 0x58);
      __s[1] = 1;
      *__s = *(undefined1 *)(iVar10 + 0x2c);
      iVar12 = _r_ip_funcs_p;
      *(undefined1 **)(iVar10 + 8) = __s;
      (**(code **)(iVar12 + 0x454))(*(code **)(iVar12 + 0x454));
      goto _L170;
    }
  }
  *(undefined1 *)(iVar10 + 0x50) = 0;
_L170:
  iVar10 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  uVar4 = *(ushort *)(iVar10 + iVar5);
  iVar12 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  iVar10 = _r_ip_funcs_p;
  *(ushort *)(iVar12 + iVar5) = uVar4 & 0x7fff;
                    /* WARNING: Could not recover jumptable at 0x0001135c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(iVar10 + 0x840))(0,param_1);
  return;
}

