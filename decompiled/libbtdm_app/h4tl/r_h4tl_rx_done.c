/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> h4tl.o -> r_h4tl_rx_done
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_h4tl_rx_done(int param_1,int param_2)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  code *UNRECOVERED_JUMPTABLE;
  uint uVar6;
  
  iVar5 = _r_modules_funcs_p;
  if (param_2 != 0) {
    if ((param_2 == 1) || (*(char *)(param_1 + 0x14) != '\0')) {
      UNRECOVERED_JUMPTABLE = *(code **)(_r_modules_funcs_p + 100);
    }
    else {
      UNRECOVERED_JUMPTABLE = *(code **)(_r_modules_funcs_p + 0x78);
    }
    goto _L71;
  }
  bVar1 = *(byte *)(param_1 + 0x14);
  if (bVar1 == 2) {
    cVar2 = *(char *)(param_1 + 0x15);
    if (cVar2 != '\x02') {
      if (cVar2 != '\x05') {
        if (cVar2 != '\x01') {
          uVar4 = 0x3ca;
          UNRECOVERED_JUMPTABLE = *(code **)(_r_plf_funcs_p + 0xc);
_L73:
                    /* WARNING: Could not recover jumptable at 0x000104f6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          (*UNRECOVERED_JUMPTABLE)
                    (*(undefined1 *)(param_1 + 0x16),"h4tl.c",uVar4,UNRECOVERED_JUMPTABLE);
          return;
        }
        uVar4 = 10;
        UNRECOVERED_JUMPTABLE = *(code **)(_r_modules_funcs_p + 0x108);
        goto _L72;
      }
      iVar5 = *(int *)(param_1 + 4);
      UNRECOVERED_JUMPTABLE = *(code **)(_r_modules_funcs_p + 0xe0);
      goto _L76;
    }
    (**(code **)(_r_ip_funcs_p + 4))
              (*(undefined2 *)(param_1 + 10),*(undefined2 *)(param_1 + 0xc),
               *(undefined2 *)(param_1 + 8),*(code **)(_r_ip_funcs_p + 4));
  }
  else if (bVar1 < 3) {
    if (bVar1 == 0) {
      uVar6 = (uint)*(byte *)(param_1 + 0x13);
      *(byte *)(param_1 + 0x15) = *(byte *)(param_1 + 0x13);
      if (uVar6 == 4) {
_L54:
                    /* WARNING: Could not recover jumptable at 0x000103aa. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (**(code **)(iVar5 + 0x6c))
                  (param_1,*(undefined1 *)((int)&h4tl_msgtype2hdrlen + uVar6),
                   *(code **)(iVar5 + 0x6c));
        return;
      }
      if (uVar6 < 5) {
        if ((uVar6 - 1 & 0xff) < 2) goto _L54;
      }
      else if (uVar6 == 5) {
                    /* WARNING: Could not recover jumptable at 0x000103ee. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (**(code **)(iVar5 + 0x6c))(8,*(code **)(iVar5 + 0x6c));
        return;
      }
      UNRECOVERED_JUMPTABLE = *(code **)(iVar5 + 100);
      goto _L71;
    }
    cVar2 = *(char *)(param_1 + 0x15);
    if (cVar2 == '\x02') {
      uVar4 = 0xb;
      UNRECOVERED_JUMPTABLE = *(code **)(_r_modules_funcs_p + 0x108);
_L72:
                    /* WARNING: Could not recover jumptable at 0x0001041c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*UNRECOVERED_JUMPTABLE)(uVar4,UNRECOVERED_JUMPTABLE);
      return;
    }
    if (cVar2 != '\x05') {
      if (cVar2 != '\x01') {
        uVar4 = 0x353;
        UNRECOVERED_JUMPTABLE = *(code **)(_r_plf_funcs_p + 0xc);
        goto _L73;
      }
      uVar4 = 9;
      UNRECOVERED_JUMPTABLE = *(code **)(_r_modules_funcs_p + 0x108);
      goto _L72;
    }
    uVar6 = (**(code **)(_r_hli_funcs_p + 0x10))
                      (*(undefined2 *)(param_1 + 0xc),*(code **)(_r_hli_funcs_p + 0x10));
    if ((uVar6 & 0xff) == 0xff) {
      iVar5 = (**(code **)(_r_modules_funcs_p + 200))
                        (0xdaf,8,*(undefined2 *)(param_1 + 0xc),*(undefined2 *)(param_1 + 0x10),
                         *(code **)(_r_modules_funcs_p + 200));
      *(undefined2 *)(iVar5 + -2) = *(undefined2 *)(param_1 + 10);
    }
    else {
      uVar4 = (**(code **)(_r_hli_funcs_p + 0x10))
                        (*(undefined2 *)(param_1 + 0xe),*(code **)(_r_hli_funcs_p + 0x10));
      iVar5 = _r_modules_funcs_p;
      *(short *)(param_1 + 0xe) = (short)uVar4;
      iVar5 = (**(code **)(iVar5 + 200))
                        (*(undefined2 *)(param_1 + 10),uVar6,uVar4,*(undefined2 *)(param_1 + 0x10),
                         *(code **)(iVar5 + 200));
    }
    iVar3 = _r_modules_funcs_p;
    if (*(short *)(param_1 + 0x10) != 0) {
      *(int *)(param_1 + 4) = iVar5;
      *(undefined2 *)(param_1 + 8) = 0;
                    /* WARNING: Could not recover jumptable at 0x000104d0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(iVar3 + 0x74))(param_1,*(code **)(iVar3 + 0x74));
      return;
    }
    UNRECOVERED_JUMPTABLE = *(code **)(_r_modules_funcs_p + 0xe0);
_L76:
    (*UNRECOVERED_JUMPTABLE)(iVar5,UNRECOVERED_JUMPTABLE);
  }
  else {
    if (bVar1 != 3) {
                    /* WARNING: Could not recover jumptable at 0x000103d4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(_r_plf_funcs_p + 8))(0,"h4tl.c",999,*(code **)(_r_plf_funcs_p + 8));
      return;
    }
    iVar5 = (**(code **)(_r_modules_funcs_p + 0x68))(*(code **)(_r_modules_funcs_p + 0x68));
    if (iVar5 == 0) {
      UNRECOVERED_JUMPTABLE = *(code **)(_r_modules_funcs_p + 0x70);
      goto _L71;
    }
  }
  UNRECOVERED_JUMPTABLE = *(code **)(_r_modules_funcs_p + 0x78);
_L71:
                    /* WARNING: Could not recover jumptable at 0x00010354. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(param_1,UNRECOVERED_JUMPTABLE);
  return;
}

