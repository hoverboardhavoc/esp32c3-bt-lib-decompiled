/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> h4tl.o -> r_h4tl_rx_done
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_h4tl_rx_done(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  code *UNRECOVERED_JUMPTABLE_00;
  undefined4 uVar3;
  int iVar4;
  undefined1 uVar5;
  uint uVar6;
  
  if (param_2 != 0) {
    if ((param_2 == 1) || (*(char *)(param_1 + 0x14) != '\0')) {
      UNRECOVERED_JUMPTABLE_00 = *(code **)(_r_modules_funcs_p + 100);
    }
    else {
      UNRECOVERED_JUMPTABLE_00 = *(code **)(_r_modules_funcs_p + 0x78);
    }
    goto _L65;
  }
  cVar1 = *(char *)(param_1 + 0x14);
  if (cVar1 == '\x01') {
    cVar1 = *(char *)(param_1 + 0x15);
    if (cVar1 == '\x02') {
      uVar3 = 0xb;
      UNRECOVERED_JUMPTABLE_00 = *(code **)(_r_modules_funcs_p + 0x108);
_L68:
                    /* WARNING: Could not recover jumptable at 0x000103ee. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*UNRECOVERED_JUMPTABLE_00)(uVar3);
      return;
    }
    if (cVar1 != '\x05') {
      if (cVar1 != '\x01') {
        uVar3 = 0x353;
        UNRECOVERED_JUMPTABLE_00 = *(code **)(_r_plf_funcs_p + 0xc);
_L67:
                    /* WARNING: Could not recover jumptable at 0x000104cc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*UNRECOVERED_JUMPTABLE_00)(*(undefined1 *)(param_1 + 0x16),"h4tl.c",uVar3);
        return;
      }
      uVar3 = 9;
      UNRECOVERED_JUMPTABLE_00 = *(code **)(_r_modules_funcs_p + 0x108);
      goto _L68;
    }
    uVar6 = (**(code **)(_r_hli_funcs_p + 0x10))
                      (*(undefined2 *)(param_1 + 0xc),*(code **)(_r_hli_funcs_p + 0x10));
    if ((uVar6 & 0xff) == 0xff) {
      iVar4 = (**(code **)(_r_modules_funcs_p + 200))
                        (0xdaf,8,*(undefined2 *)(param_1 + 0xc),*(undefined2 *)(param_1 + 0x10),
                         *(code **)(_r_modules_funcs_p + 200));
      *(undefined2 *)(iVar4 + -2) = *(undefined2 *)(param_1 + 10);
    }
    else {
      uVar3 = (**(code **)(_r_hli_funcs_p + 0x10))
                        (*(undefined2 *)(param_1 + 0xe),*(code **)(_r_hli_funcs_p + 0x10));
      iVar4 = _r_modules_funcs_p;
      *(short *)(param_1 + 0xe) = (short)uVar3;
      iVar4 = (**(code **)(iVar4 + 200))
                        (*(undefined2 *)(param_1 + 10),uVar6,uVar3,*(undefined2 *)(param_1 + 0x10),
                         *(code **)(iVar4 + 200));
    }
    iVar2 = _r_modules_funcs_p;
    if (*(short *)(param_1 + 0x10) != 0) {
      *(int *)(param_1 + 4) = iVar4;
      *(undefined2 *)(param_1 + 8) = 0;
                    /* WARNING: Could not recover jumptable at 0x000104a4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(iVar2 + 0x74))(param_1);
      return;
    }
    UNRECOVERED_JUMPTABLE_00 = *(code **)(_r_modules_funcs_p + 0xe0);
_L71:
    (*UNRECOVERED_JUMPTABLE_00)(iVar4,UNRECOVERED_JUMPTABLE_00);
  }
  else {
    if (cVar1 == '\0') {
      uVar6 = (uint)*(byte *)(param_1 + 0x13);
      *(byte *)(param_1 + 0x15) = *(byte *)(param_1 + 0x13);
      if (uVar6 == 4) {
_L49:
        UNRECOVERED_JUMPTABLE_00 = *(code **)(_r_modules_funcs_p + 0x6c);
        uVar5 = *(undefined1 *)((int)&h4tl_msgtype2hdrlen + uVar6);
_L66:
                    /* WARNING: Could not recover jumptable at 0x000103ac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*UNRECOVERED_JUMPTABLE_00)(param_1,uVar5);
        return;
      }
      if (uVar6 < 5) {
        if ((uVar6 - 1 & 0xff) < 2) goto _L49;
      }
      else if (uVar6 == 5) {
        UNRECOVERED_JUMPTABLE_00 = *(code **)(_r_modules_funcs_p + 0x6c);
        uVar5 = 8;
        goto _L66;
      }
      UNRECOVERED_JUMPTABLE_00 = *(code **)(_r_modules_funcs_p + 100);
      goto _L65;
    }
    if (cVar1 == '\x02') {
      cVar1 = *(char *)(param_1 + 0x15);
      if (cVar1 != '\x02') {
        if (cVar1 != '\x05') {
          if (cVar1 != '\x01') {
            uVar3 = 0x3ca;
            UNRECOVERED_JUMPTABLE_00 = *(code **)(_r_plf_funcs_p + 0xc);
            goto _L67;
          }
          uVar3 = 10;
          UNRECOVERED_JUMPTABLE_00 = *(code **)(_r_modules_funcs_p + 0x108);
          goto _L68;
        }
        iVar4 = *(int *)(param_1 + 4);
        UNRECOVERED_JUMPTABLE_00 = *(code **)(_r_modules_funcs_p + 0xe0);
        goto _L71;
      }
      (**(code **)(_r_ip_funcs_p + 4))
                (*(undefined2 *)(param_1 + 10),*(undefined2 *)(param_1 + 0xc),
                 *(undefined2 *)(param_1 + 8),*(code **)(_r_ip_funcs_p + 4));
    }
    else {
      if (cVar1 != '\x03') {
                    /* WARNING: Could not recover jumptable at 0x00010366. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (**(code **)(_r_plf_funcs_p + 8))(0,"h4tl.c",999);
        return;
      }
      iVar4 = (**(code **)(_r_modules_funcs_p + 0x68))(*(code **)(_r_modules_funcs_p + 0x68));
      if (iVar4 == 0) {
        UNRECOVERED_JUMPTABLE_00 = *(code **)(_r_modules_funcs_p + 0x70);
        goto _L65;
      }
    }
  }
  UNRECOVERED_JUMPTABLE_00 = *(code **)(_r_modules_funcs_p + 0x78);
_L65:
                    /* WARNING: Could not recover jumptable at 0x00010328. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE_00)(param_1);
  return;
}

